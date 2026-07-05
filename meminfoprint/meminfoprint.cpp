#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QString>
#include <QDebug>
/*
int main(int argc, char* argv[]) {
    QFile meminfo("/proc/meminfo");
    if (!meminfo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open /proc/meminfo";
        return -1;
    }

    QTextStream in(&meminfo);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
        if (line.startsWith("MemAvailable:")) {
            qDebug() << "Found Match:";
            qDebug() << line.trimmed();
            break;
        }
    }
    meminfo.close();
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/prctl.h>

void print_trace() {
    char pid_buf[30];
    sprintf(pid_buf, "%d", getpid());
    char name_buf[512];
    name_buf[readlink("/proc/self/exe", name_buf, 511)]=0;
    prctl(PR_SET_PTRACER, PR_SET_PTRACER_ANY, 0, 0, 0);
    int child_pid = fork();
    if (!child_pid) {
        dup2(2,1); // redirect output to stderr - edit: unnecessary?
        execl("/usr/bin/gdb", "gdb", "--batch", "-n", "-ex", "thread", "-ex", "bt", name_buf, pid_buf, NULL);
        abort(); // If gdb failed to start
    } else {
        waitpid(child_pid,NULL,0);
    }
}

#include <signal.h>

void signalHandler(int signum) {

    switch (signum) {
        case SIGSEGV:
            qDebug() << "Segmentation fault occurred!";
            break;
        case SIGILL:
            qDebug() << "Illegal instruction occurred!";
            break;
        case SIGBUS:
            qDebug() << "Bus error occurred!";
            break;
        case SIGFPE:
            qDebug() << "Floating-point exception occurred!";
            break;
        case SIGABRT:
            qDebug() << "Abnormal termination (abort) occurred!";
            break;
        // Add more signals as needed, but these are the most common for crashes.
        // Avoid handling SIGTERM, SIGHUP, SIGINT if you want graceful shutdown.
        default:
            qDebug() << "Unhandled crash signal!";
            break;
    }
    print_trace();

    if (signum == SIGSEGV) {
        qDebug() << "Segmentation fault occurred!";
        qDebug() << "MemInfo:Segv at the time of exiting:";
        // You can add more logging or error handling here
        exit(EXIT_FAILURE); // Exit the application
    }
    qDebug() << "MemInfo:Before Exiting:";

}
//int main_dev(int argc, char *argv[])
int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    qDebug() << "Inside main:";
    signal(SIGSEGV, signalHandler);
    signal(SIGILL, signalHandler);  // Illegal instruction
    signal(SIGBUS, signalHandler);  // Bus error
    signal(SIGFPE, signalHandler);  // Floating-point exception
    signal(SIGABRT, signalHandler); // Abort signal
    signal(SIGTERM, signalHandler);
    signal(SIGHUP, signalHandler);
    signal(SIGINT, signalHandler);
    qDebug() << "Before creating QFile:";
    QFile meminfo("/proc/meminfo");
    qDebug() << "After creating QFile; Before meminfo.open:";    
    if (!meminfo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open /proc/meminfo";
        return -1;
    }
    qDebug() << "Before creating QTextStream:";    
    QTextStream in(&meminfo);
    qDebug() << "After creating QTextStream; Before While loop:" << !in.atEnd();    
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
        if (line.startsWith("MemAvailable:")) {
            qDebug() << "Found Match:";
            qDebug() << line.trimmed();
            break;
        }
    }
    meminfo.close();
}


#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "constructor of Singleton begins" << endl;
        sleep(1);
        cout << "constructor of Singleton ends" << endl;
    }

public:
    static Singleton* getInstance()
    {
        if (m_singleton == NULL) {
            m_singleton = new Singleton();
            count++;
        }
            
        return m_singleton;
    }

    static Singleton* freeInstance()
    {
        if (m_singleton != NULL)
        {
            delete m_singleton;
            m_singleton = NULL;
        }
        return m_singleton;
    }

private:
    static Singleton* m_singleton;
    static int count;
};

Singleton* Singleton::m_singleton = NULL; //静态成员变量初始化
int Singleton::count = 0;

void* thread_main(void* arg) {
    Singleton::getInstance();
    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, thread_main, NULL);
    pthread_create(&t2, NULL, thread_main, NULL);
    pthread_create(&t3, NULL, thread_main, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}

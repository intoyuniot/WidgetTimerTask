#ifndef WIDGET_TIMER_TASK_H_
#define WIDGET_TIMER_TASK_H_

#include "application.h"


class WidgetTimerTask: public WidgetBaseClass
{
    public:
        WidgetTimerTask(uint8_t ucItem = 0);
        ~WidgetTimerTask();
        void begin(void (*UserCallBack)(void) = NULL);
        void displayRemain(int remain);
        int getTimer(void);

    private:
        char pDataRemainTopic[64];
        char pCmdTimeTopic[64];
        uint8_t _Item=0;
        int _time;
        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);

};

#endif

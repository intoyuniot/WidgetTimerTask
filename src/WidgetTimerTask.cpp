#include "WidgetTimerTask.h"


WidgetTimerTask::WidgetTimerTask(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pDataRemainTopic,0,sizeof(pDataRemainTopic));
    memset(pCmdTimeTopic,0,sizeof(pCmdTimeTopic));

    sprintf(pDataRemainTopic,"channel/timerTask_%d/data/remain",_Item);
    sprintf(pCmdTimeTopic,"channel/timerTask_%d/cmd/time",_Item);
}

WidgetTimerTask::~WidgetTimerTask()
{

}

void WidgetTimerTask::begin(void (*UserCallBack)(void))
{
    _EventCb = UserCallBack;
    IntoRobot.subscribe(pCmdTimeTopic, NULL, this);
}

void WidgetTimerTask::displayRemain(int remain)
{
    IntoRobot.publish(pDataRemainTopic,remain);
}

int WidgetTimerTask::getTimer(void)
{
    return _time;
}

void WidgetTimerTask::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    _time = atoi((char *)payload);
    _EventCb();
}







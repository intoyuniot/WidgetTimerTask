/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 日期:  03-30-15
 ************************************************************************
 功能描述：
 定时器：定时一段时间

 所需器件:

 此例程目前只支持Atom核心板。但是此库不受限制。
 */

#include <WidgetTimerTask.h>

IntoRobotIntervalTimer myTimer;
int timeValue;

WidgetTimerTask timerTask = WidgetTimerTask();

void TimerCb(void)
{
    timeValue = timerTask.getTimer();
    if(timeValue > 0)
    {
        myTimer.begin(TimingCb, 2000, hmSec);
    }
}

void TimingCb(void)
{
    if(timeValue > 0)
    {
        timeValue--;
    }
    else
    {
        myTimer.end();
    }
    timerTask.displayRemain(timeValue);
    //用户代码请添加在此处
}

void setup()
{
    timerTask.begin(TimerCb);
}

void loop()
{

}

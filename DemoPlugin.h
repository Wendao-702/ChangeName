#ifndef REPARAMINPUTPAGE_H
#define REPARAMINPUTPAGE_H

#include "PluginEditorBase.h"

#include <QtWidgets/QtWidgets>


class DemoPlugin : public PluginEditorBase
{
    Q_OBJECT

public:
    DemoPlugin(QWidget *parent = 0);
    ~DemoPlugin();


public slots:
    virtual void onRequestFlowRun(IO_FlowDiagram* runDiagram);//流程请求运行时触发，可在此进行输入校验、保存
    virtual void onComponentRunFinished(IO_Component* finishedComponent);//组件运行结束
    virtual void onFlowDiagramRunFinished(IO_FlowDiagram* finishedDiagram);//流程运行结束
    virtual void onReceiveMonitorData(int monitorType, QString sMonitorData, IO_FlowDiagram* FlowDiagram);//实时监控对象回传槽函数


public:
    virtual int checkInputParam();//校验输入参数
    virtual int checkResultParam(IO_Component* checkComp = NULL);//校验结果参数
    virtual void InitUI(IOObject* pParentApp, QWidget* pParentWidget);//初始化
    virtual void Refreash(IOObject* pParentApp, QWidget* pParentWidget);//加载结果
    virtual void reloadResult(IO_FlowDiagram* reloadFlowDiagram);//重新载入结果

private:
    void createWidget();//构建界面
	int checkInputFile();//检查输入文件


private:
    IOObject* m_pParentApp;//总的父类
    IO_FlowDiagram* m_pCurrentDiagram;//整个流程
    IO_FlowControl * m_pFlowControl;//流程控制

    QString m_workDir;//work目录
    QString m_designDir;//design目录
    QString m_UIDir;//UI目录
    QString m_resourcesDir;//Resources目录

    int flowType;//获取当前流程类型 0：普通APP流程 1：流程定制流程


private:


};


#endif 

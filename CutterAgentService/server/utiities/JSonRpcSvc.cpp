#include "JSonRpcSvc.h"
#include "QDebug"
JSonRpcSvc::JSonRpcSvc()
{
    connect(&http, SIGNAL(done(bool )), this, SLOT(on_http_done(bool )));
    connect(&http, SIGNAL(stateChanged(int)), this, SLOT(on_http_stateChanged(int)));
    connect(&http, SIGNAL(dataReadProgress(int, int)), this, SLOT(on_http_dataReadProgress(int, int)));
    connect(&http, SIGNAL(dataSendProgress(int, int)), this, SLOT(on_http_dataSendProgress(int, int)));

    connect(&http, SIGNAL(requestFinished(int, bool)), this, SLOT(on_http_requestFinished(int, bool)));
    connect(&http, SIGNAL(requestStarted(int)), this, SLOT(on_http_requestStarted(int)));
    connect(&http, SIGNAL(responseHeaderReceived(const QHttpResponseHeader &)), this, SLOT(on_http_responseHeaderReceived(const QHttpResponseHeader &)));
}

JSonRpcSvc::~JSonRpcSvc(){
    //disconnect(&http, SIGNAL(done(bool )), this, SLOT(on_http_done(bool )));
}

bool JSonRpcSvc::post(const QUrl &url,QMap<QString,QString> &map){
    this->isFilished = false;
    QString params = "";
    QString key,value;
    QList<QString> list = map.keys();
    QListIterator<QString> i(list);

    while (i.hasNext()){
        key=i.next();
        value=map.value(key);
        params.append(key).append("=").append(value);
        if (key.toLower() == "evtid"){
            evtid= value;
        }
        if (i.hasNext()){
            params.append("&");
        }
    }

    params = params.replace(" ","%20");

    http.setObjectName("http");


 qDebug()<<"http params:"<<params<<endl;

//    http.post(url.path(),params.toUtf8());

//    http.close();

    http.setHost(url.host(),url.port());



QString t=url.path()+"?"+params;
qDebug()<<t<<endl;
    QHttpRequestHeader header("POST",t ) ;
        header.setValue("Host", url.host()) ;
        header.setContentType("application/x-www-form-urlencoded");
        http.request(header, params.toUtf8()) ;
    return true;

}

void JSonRpcSvc::on_http_done(bool error)
{
    QString result;
    bool isOk=error;
    if (error)
    {
        result="error";
       // qDebug()  <<" =========http error=======" << http.errorString() << "\n";
    }
    else
    {
        result = http.readAll();

        //qDebug()<<"-----------------on_http_done:"<<result<<endl;
    }
    if (this->isFilished){
        emit httpDone(!error,evtid,result);
    }
}

void JSonRpcSvc::on_http_dataReadProgress(int done, int total)
{
    qDebug() << "Downloaded " << done << " bytes " << " out of " << total << "\n";
}

void JSonRpcSvc::on_http_dataSendProgress(int done, int total)
{
    qDebug() << "Sended " << done << " bytes " << " out of " << total << "\n";
}



void JSonRpcSvc::on_http_requestFinished(int id, bool error)
{
    qDebug() << id <<" Request Finished\n";

    if (error)
    {
        qDebug() << "with errors\n";
        qDebug() << http.errorString() << "\n";
    }
    else
    {
        qDebug() << " successfully \n";
    }
}

void JSonRpcSvc::on_http_requestStarted(int id)
{
    qDebug() << "Request Started\n";
}

void JSonRpcSvc::on_http_responseHeaderReceived(const QHttpResponseHeader &resp)
{
    qDebug() << "HTTP response header received \n";
}


void JSonRpcSvc::on_http_stateChanged(int stat)
{
    switch (stat)
    {
        case QHttp::Unconnected : qDebug() << "Unconnected\n" ;
              break;
        case QHttp::HostLookup : qDebug() << "HostLookup\n" ;
              break;
        case QHttp::Connecting : qDebug() << "Connecting\n" ;
              break;
        case QHttp::Sending : qDebug() << "Sending\n" ;
              break;
        case QHttp::Reading : qDebug() << "Reading\n" ;
              break;
        case QHttp::Connected : {
            qDebug() << "Connected\n" ;

            this->isFilished = true;
        }
              break;
        case QHttp::Closing : qDebug() << "Closing\n" ;
              break;
    }
}

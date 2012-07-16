#include <QObject>

class QLocalServer;

class Server : public QObject {
  Q_OBJECT

  public:
    Server(QObject *parent);
    ~Server();
    bool start();
    QString server_name();

  public slots:
    void handleConnection();

  private:
    QLocalServer *m_server;
};


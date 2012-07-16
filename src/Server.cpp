#include "Server.h"
#include "Connection.h"
#include "WebPageManager.h"

#include <QLocalServer>

Server::Server(QObject *parent) : QObject(parent) {
  m_server = new QLocalServer(this);
}

Server::~Server() {
  if (m_server->isListening()) {
    m_server->close();
    m_server->removeServer("capybara-webkit");
  }
}

bool Server::start() {
  connect(m_server, SIGNAL(newConnection()), this, SLOT(handleConnection()));
  return m_server->listen("capybara-webkit");
}

QString Server::server_name() {
  return m_server->fullServerName();
}

void Server::handleConnection() {
  QLocalSocket *socket = m_server->nextPendingConnection();
  new Connection(socket, new WebPageManager(this), this);
}

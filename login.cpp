#include "login.h"
#include "database.h"

Login::Login(QWidget* parent): QDialog(parent)
{
    database.connectDb();

    setFixedSize(300, 120);
    setWindowTitle("Login");
    setModal(true);
    setAttribute(Qt::WA_DeleteOnClose);

    userLabel = new QLabel("Username:");
    passLabel = new QLabel("Password:");
    userLineEdit = new QLineEdit();
    passLineEdit = new QLineEdit();
    passLineEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login");
    quitButton = new QPushButton("Quit");

    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox1 = new QHBoxLayout();
    QHBoxLayout* hbox2 = new QHBoxLayout();
    QHBoxLayout* hbox3 = new QHBoxLayout();

    hbox1->addWidget(userLabel, 1);
    hbox1->addWidget(userLineEdit, 2);
    hbox2->addWidget(passLabel, 1);
    hbox2->addWidget(passLineEdit, 2);
    hbox3->addWidget(loginButton, 1, Qt::AlignRight);
    hbox3->addWidget(quitButton, 0, Qt::AlignRight);

    vbox->addSpacing(1);
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(OnQuit()));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(OnLogin()));
}
void Login::reject()
{
    OnQuit();
}

void Login::OnQuit()
{
    this->close();
    parentWidget()->close();
}

void Login::OnLogin()
{
    QString username = userLineEdit->text();
    QString password = passLineEdit->text();

    // Checking if username or password is empty
    if (username.isEmpty() || password.isEmpty())
        QMessageBox::information(this, tr("Baran!"), "Username baran password baran");

    QSqlQuery query;
    query.exec("SELECT * FROM users WHERE username = '" + username + "' AND password = '" + password + "'");


    bool flag = false;
    while (query.next()) {

        QString username = query.value(3).toString();
        QString password = query.value(4).toString();

        if(!username.isEmpty() && !password.isEmpty())
        {
            flag = true;
            break;
        }

    }

    // if(username != "baran" && password != "baran")
    if(flag == false)
    {
        parentWidget()->close();
    }
    else
    {
        this->destroy();
    }
}
Login::~Login() {}


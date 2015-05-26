#include <QCoreApplication>

#include "scanner.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationDomain("ahlforn.net");
    QCoreApplication::setApplicationName("Reddit Scanner");
    QCoreApplication::setApplicationVersion("0.1.1");

    QSettings settings;
    QCommandLineParser parser;

    parser.setApplicationDescription("Scans reddit/subreddits for images.");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("source", "Url of subreddit");
    parser.addPositionalArgument("destination", "path for files to be stored in.");

    QCommandLineOption optionLimit(QStringList() << "l" << "limit", "Limit on downloaded images. Default = 100", "Limit");
    QCommandLineOption optionID(QStringList() << "i" << "id", "Client ID for Imgur.", "ClientID");

    parser.addOption(optionLimit);
    parser.addOption(optionID);

    parser.process(a);

    const QStringList args = parser.positionalArguments();

    QString url = (args.length() > 0 && !args.at(0).isEmpty()) ? args.at(0) : settings.value("url").toString();
    QString path = (args.length() > 0 && !args.at(1).isEmpty()) ? args.at(1) : settings.value("path").toString();
    int limit = (!parser.value(optionLimit).isEmpty()) ? parser.value(optionLimit).toInt() : settings.value("limit", 100).toInt();
    QString id = (!parser.value(optionID).isEmpty()) ? parser.value(optionID) : settings.value("clientID").toString();

    Scanner scanner;
    scanner.setUrl(QUrl(url + ".json"));
    scanner.setLimit(limit);
    scanner.setClientID(id);
    scanner.setPath(path);
    scanner.scan();

    return a.exec();
}

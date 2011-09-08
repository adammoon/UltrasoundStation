#ifndef QFILTERFACTORY_H
#define QFILTERFACTORY_H
class QFilter;
class QFilterFactory{
    QFilter* getFilterByName(QString& filterName);
};

#endif // QFILTERFACTORY_H

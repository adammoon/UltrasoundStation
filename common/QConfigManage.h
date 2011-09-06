#ifndef QCONFIGMANAGE_H
#define QCONFIGMANAGE_H
class QString;
class QDir;
class QFile;
class QSettings;        /**< qt 的配置文件读写类*/
class QVariant;
//!QConfigManager
/*!
*\name QConfigManager
*\brief 用于管理系统的配置文件，包括读取，修改，增加，删除操作
*\author flyfish
*\date 2011-9-5
*/
class QConfigManager{
public:
    static QString keyLoadLogFileName;
    //!initCfgManager
    static void initCfgManager();
    //!getKeyValue
    /*!
    *\brief 获取一个项的值
    *\param key:关键字；sec：关键字所在节名
    *\author flyfish
    *\date 2011-09-06
    */
    QVariant getKeyValue(const QString& key);
    //!writeKeyValue
    /*!
    *\brief 写入值，如果存在，则覆盖
    *\param sec:节；key：关键字；value:值
    *\author flyfish
    *\date 2011-09-06
    */
    void writeKeyValue(const QString& key,QVariant value);
private:
    QConfigManager();
    ~QConfigManager();
    static QSettings configFile;
};

#endif // QCONFIGMANAGE_H

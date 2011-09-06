#ifndef QCONFIGMANAGE_H
#define QCONFIGMANAGE_H
class QString;
class QDir;
class QFile;
class QSettings;        /**< qt �������ļ���д��*/
class QVariant;
//!QConfigManager
/*!
*\name QConfigManager
*\brief ���ڹ���ϵͳ�������ļ���������ȡ���޸ģ����ӣ�ɾ������
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
    *\brief ��ȡһ�����ֵ
    *\param key:�ؼ��֣�sec���ؼ������ڽ���
    *\author flyfish
    *\date 2011-09-06
    */
    QVariant getKeyValue(const QString& key);
    //!writeKeyValue
    /*!
    *\brief д��ֵ��������ڣ��򸲸�
    *\param sec:�ڣ�key���ؼ��֣�value:ֵ
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

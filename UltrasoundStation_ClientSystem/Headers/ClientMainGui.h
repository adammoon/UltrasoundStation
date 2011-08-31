/*!
 * @file ClientMainGui.h
 * @brief The MainGUI for client system(start GUI)
 * @details when the client system started by user
 * this MainGui should be init for user
 * @author flyfish
 * @version 0.0.1
 * @date 2011.8.27
 */
#ifndef __QMAINWIDNOW__
#define __QMAINWINDOW__
#include <QMainWindow>
//Qt classes declare
class QMenuBar;
class QStatusBar;
class QPixmap;
//!The Main GUI Window for client system
/*!
  Window style for contain subwidget(use single-modle)
*/
class QClientMainGui:public QMainWindow{
public://functions
    //!����ģʽ�Ļ�ȡ�������
    /*!
      *@brief ��ȡ��ǰ���
      *@details
      *@param void
      *@return ָ��QClientMainGui�����ָ��
      *@author flyfish
      *@date 2011-8-27
      */
    static QClientMainGui* getGuiInstance(void);
    //!��������
    /*!
      delete all the sub_widgets
    */
    ~QClientMainGui();
public://types
    //!status enum
    /*!
      represent the status of the MainGui window
    */
    typedef enum{
        ENUM_SHOWNEWREPORT,/*!< STATUS:�½�.*/
        ENUM_SHOWOLDREPORT /*!< STATUS:���.*/
    }SHOW_STATUS;
private://functions
    //!���캯��
    /*!
    * @brief ����������
    * @details ���ÿؼ������Լ���ʼ״̬
    * @param parent��ָ�򸸴��ڵ�ָ�룬Ĭ��Ϊ0
    * @return NA
    * @author flyfish
    * @date 2011-8-27
    */
    QClientMainGui(QWidget* parent=0/**< [in] ������ָ��*/);
    //!���ò˵���
    /*!
    * @brief ���������ڵĲ˵���
    * @details �����˵���
    * @param void
    * @return bool��true:operate successful,false:opreate failed
    * @author flyfish
    * @date 2011-8-27
    */
    bool setMenuContext(void);
    //!�����ź����
    /*!
    * @brief ���ӱ������ź���ؼ��Ĳۺ���
    * @details
    * @param NA
    * @return NA
    * @author flyfish
    * @date 2011-8-27
    */
    void signal_slots_connect(void)const;
    //reimplement
    //void paintEvent(QPaintEvent *);
private://members
    static QClientMainGui* mainGui; /**< static pointer to reference the only object of QClientMainGui */

    QMenuBar* mainMenuBar;    /**< �˵��� */
    QStatusBar* mainStatusBar;   /**< ״̬�� */
    SHOW_STATUS currentStatus;  /**< ��ǰ״̬ */
};
#endif

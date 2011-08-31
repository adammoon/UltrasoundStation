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
    //!单件模式的获取句柄函数
    /*!
      *@brief 获取当前句柄
      *@details
      *@param void
      *@return 指向QClientMainGui对象的指针
      *@author flyfish
      *@date 2011-8-27
      */
    static QClientMainGui* getGuiInstance(void);
    //!析构函数
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
        ENUM_SHOWNEWREPORT,/*!< STATUS:新建.*/
        ENUM_SHOWOLDREPORT /*!< STATUS:浏览.*/
    }SHOW_STATUS;
private://functions
    //!构造函数
    /*!
    * @brief 创建主窗口
    * @details 设置控件布局以及初始状态
    * @param parent：指向父窗口的指针，默认为0
    * @return NA
    * @author flyfish
    * @date 2011-8-27
    */
    QClientMainGui(QWidget* parent=0/**< [in] 父窗口指针*/);
    //!设置菜单栏
    /*!
    * @brief 创建主窗口的菜单栏
    * @details 基本菜单项
    * @param void
    * @return bool，true:operate successful,false:opreate failed
    * @author flyfish
    * @date 2011-8-27
    */
    bool setMenuContext(void);
    //!连接信号与槽
    /*!
    * @brief 连接本窗口信号与控件的槽函数
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

    QMenuBar* mainMenuBar;    /**< 菜单栏 */
    QStatusBar* mainStatusBar;   /**< 状态栏 */
    SHOW_STATUS currentStatus;  /**< 当前状态 */
};
#endif

#ifndef TABSSETTINGSEDITOR_H
#define TABSSETTINGSEDITOR_H

#include "ui_tabssettingsform.h"
#include <QWidget>


class QtMaterialTabs;

class TabsSettingsEditor : public QWidget {
  Q_OBJECT

public:
  explicit TabsSettingsEditor(QWidget *parent = 0);
  ~TabsSettingsEditor();

protected slots:
  void setupForm();
  void updateWidget();

private:
  Ui::TabsSettingsForm *const ui;
  QtMaterialTabs *const m_tabs;
};

#endif // TABSSETTINGSEDITOR_H

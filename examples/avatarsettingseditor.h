#ifndef AVATARSETTINGSEDITOR_H
#define AVATARSETTINGSEDITOR_H

#include "ui_avatarsettingsform.h"
#include <QWidget>


class QtMaterialAvatar;

class AvatarSettingsEditor : public QWidget {
  Q_OBJECT

public:
  explicit AvatarSettingsEditor(QWidget *parent = 0);
  ~AvatarSettingsEditor();

protected slots:
  void setupForm();
  void updateWidget();
  void selectColor();

private:
  Ui::AvatarSettingsForm *const ui;
  QtMaterialAvatar *const m_avatar;
};

#endif // AVATARSETTINGSEDITOR_H

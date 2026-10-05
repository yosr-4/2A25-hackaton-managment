#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "competition.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    // ----- mise en place (une fois, au démarrage)
    void setupNavigation();
    void setupTable();
    void setupFilters();
    void setupAddForm();

    // ----- formulaire d'ajout (colonne droite, sous les détails)
    void resetAddForm();
    void showAddError(const QString &msg);
    void submitAddForm();

    // ----- actions sur les compétitions
    void editCompetition(const QString &id);
    void deleteCompetition(const QString &id);
    void selectRow(const QString &id);
    void showDetails();
    void notImplemented(const QString &module);

    // ----- affichage
    void onSelect();
    void onFilter();
    void resetFilters();
    void refreshYears();
    void refresh(bool rebuildYears = true);
    void buildPager(int pages);
    void goTo(int p);
    void updateKpis();
    void updateDetails();
    QWidget *makeBadge(const QString &statut);
    QWidget *makeActions(const QString &id);

    // ----- utilitaires
    QString nextId() const;
    int indexOf(const QString &id) const;
    QVector<Comp> applyFilters() const;

    Ui::MainWindow *ui;          // tous les widgets dessinés dans mainwindow.ui
    QVector<Comp> data, filtered;
    int page = 0;
    QString selectedId;
};

#endif // MAINWINDOW_H

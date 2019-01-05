#ifndef TEMPLATE_WINDOW_HPP
#define TEMPLATE_WINDOW_HPP

#include <QGraphicsScene>
#include <QKeyEvent>

#include "centered_window.hpp"
#include "furniture.hpp"

namespace Ui {
class TemplateWindow;
}

class TemplateWindow : public CenteredWindow /*QMainWindow*/
{
    Q_OBJECT

public:
    explicit TemplateWindow(QWidget *parent = nullptr,
                            QList<QGraphicsItem*> roomList = QList<QGraphicsItem*>() );
    ~TemplateWindow() override;     // 'override' needed cause of keypressevent, not sure why
    void keyPressEvent(QKeyEvent *event) override;

    void drawRooms();
    void drawGraphicsScene();
    void setDefaultApartmentScheme();

private:
    Ui::TemplateWindow *ui;
    QGraphicsScene *scene;
    QList<QGraphicsItem*> m_roomList;
    QList<Furniture*> m_doorList;
    double m_roomArea;

private slots:

    /* Menu bar options */
    void on_actionClear_All_triggered();
    void on_actionShortcuts_triggered();
    void on_actionQuit_triggered();
    void on_SaveAsImage_triggered();
    void on_actionStatsInfo_triggered();
    void on_actionExportProject_triggered();
    void on_actionImportProject_triggered();

    /* Item manipulation */
    void on_btnFlip_clicked();
    void on_btnMoveLeft_clicked();
    void on_btnMoveRight_clicked();
    void on_btnDeleteItem_clicked();
    void on_btnRotateLeft_clicked();
    void on_btnRotateRight_clicked();
    void on_btnRotate90Left_clicked();
    void on_btnRotate90Right_clicked();

    /* Scene manipulation */
    void on_btnZoomIn_clicked();
    void on_btnZoomOut_clicked();
    void on_btnCenterScene_clicked();
    void on_btnRotateSceneLeft_clicked();
    void on_btnRotateSceneRight_clicked();

    /* Furniture */

    /* SOFAS */
    void on_btnSofa1_Black_clicked();
    void on_btnSofa1_White_clicked();
    void on_btnSofa1_Blue_clicked();
    void on_btnSofa1_Purple_clicked();
    void on_btnSofa1_Red_clicked();
    void on_btnSofa1_Beige_clicked();
    void on_btnSofa1_Green_clicked();
    void on_btnSofa2_Grey_clicked();
    void on_btnSofa2_White_clicked();
    void on_btnSofa2_Red_clicked();
    void on_btnSofa2_Yellow_clicked();
    /* CORNER SOFAS */
    void on_btnCornerSofa1_Black_clicked();
    void on_btnCornerSofa1_Beige_clicked();
    void on_btnCornerSofa1_White_clicked();
    void on_btnCornerSofa1_Brown_clicked();
    void on_btnCornerSofa1_Red_clicked();
    void on_btnCornerSofa1_Purple_clicked();
    void on_btnCornerSofa1_Blue_clicked();
    void on_btnCornerSofa1_Skyblue_clicked();
    void on_btnCornerSofa1_Green_clicked();
    void on_btnCornerSofa2_Beige_clicked();
    void on_btnCornerSofa2_Purple_clicked();
    void on_btnCornerSofa2_Blue_clicked();
    void on_btnCornerSofa3_Black_clicked();
    void on_btnCornerSofa3_White_clicked();
    void on_btnCornerSofa3_Beige_clicked();
    void on_btnCornerSofa3_Red_clicked();
    void on_btnCornerSofa3_Purple_clicked();
    void on_btnCornerSofa3_Blue_clicked();
    void on_btnCornerSofa4_Black_clicked();
    void on_btnCornerSofa4_White_clicked();
    /* BENCHES */
    void on_btnBenchBamboo_clicked();
    void on_btnBenchWooden_Light_clicked();
    void on_btnBenchWooden_Dark_clicked();
    /* ARMCHAIRS */
    void on_btnArmchair1_black_clicked();
    void on_btnArmchair1_white_clicked();
    void on_btnArmchair1_green_clicked();
    void on_btnArmchair1_blue_clicked();
    void on_btnArmchair1_orange_clicked();
    void on_btnArmchair1_red_clicked();
    void on_btnArmchair2_lightgrey_clicked();
    void on_btnArmchair2_lightgreen_clicked();
    void on_btnArmchair3_black_clicked();
    void on_btnArmchair3_red_clicked();
    void on_btnArmchair3_purple_clicked();
    void on_btnArmchair3_blue_clicked();
    void on_btnArmchair3_green_clicked();
    void on_btnArmchair4_purple_clicked();
    void on_btnArmchair4_blue_clicked();
    void on_btnTabouret_black_clicked();
    void on_btnTabouret_brown_clicked();
    void on_btnTabouret_white_clicked();
    void on_btnTabouret_blue_clicked();
    /* TABLES */
    void on_btnTable1_dark_clicked();
    void on_btnTable1_grey_clicked();
    void on_btnTable1_light_clicked();
    void on_btnTable1_white_clicked();
    void on_btnTable2_darkblue_clicked();
    void on_btnTable2_dark_clicked();
    void on_btnTable2_light_clicked();
    void on_btnTable2_grey_clicked();
    void on_btnTable2_white_clicked();
    void on_btnTable3_dark_clicked();
    void on_btnTable3_light_clicked();
    void on_btnTable4_dark_clicked();
    void on_btnTable4_light_clicked();
    void on_btnTable5_dark_clicked();
    void on_btnTable5_blue_clicked();
    void on_btnTable5_brown_clicked();
    void on_btnTable6_dark_clicked();
    void on_btnTable6_light_clicked();
    void on_btnTable7_dark_clicked();
    void on_btnTable7_light_clicked();
    void on_btnTableGlass_clicked();
    void on_btnTVStand_brown_clicked();
    void on_btnTVStand_darkgrey_clicked();
    void on_btnTVStand_lightgrey_clicked();
    void on_btnTVStand_dark_clicked();
    /* CHAIRS */
    void on_btnChair1_black_clicked();
    void on_btnChair1_grey_clicked();
    void on_btnChair1_blue_clicked();
    void on_btnChair1_red_clicked();
    void on_btnChair1_yellow_clicked();
    void on_btnChair2_light_clicked();
    void on_btnChair2_dark_clicked();
    void on_btnChair3_dark_clicked();
    void on_btnChair3_light_clicked();
    void on_btnStool_brown_clicked();
    void on_btnStool_light_clicked();
    /* CABINETS */
    void on_btnNightTable_darkblue_clicked();
    void on_btnNightTable_normal_clicked();
    void on_btnNightTable_white_clicked();
    void on_btnCabinet1_brown_clicked();
    void on_btnCabinet1_light_clicked();
    void on_btnCabinet1_white_clicked();
    void on_btnCabinet2_dark_clicked();
    void on_btnCabinet2_brown_clicked();
    void on_btnCabinet3_dark_clicked();
    void on_btnCabinet3_light_clicked();
    /* WARDROBES */
    void on_btnWardrobe1_black_clicked();
    void on_btnWardrobe1_grey_clicked();
    void on_btnWardrobe1_white_clicked();
    void on_btnWardrobe1_brown_clicked();
    void on_btnWardrobe1_normal_clicked();
    void on_btnWardrobe1_light_clicked();
    void on_btnWardrobe2_black_clicked();
    void on_btnWardrobe2_grey_clicked();
    void on_btnWardrobe2_white_clicked();
    void on_btnWardrobe2_dark_clicked();
    void on_btnWardrobe2_normal_clicked();
    void on_btnWardrobe2_light_clicked();
    void on_btnWardrobe3_clicked();
    /* KITCHEN */
    void on_btnBottomCabinet1_clicked();
    void on_btnBottomCabinet2_clicked();
    void on_btnBottomCabinet3_clicked();
    void on_btnTopCabinet1_clicked();
    void on_btnTopCabinet2_clicked();
    void on_btnTopCabinet3_clicked();
    void on_btnStove_clicked();
    /* SINKS */
    void on_btnSink1_clicked();
    void on_btnSink2_clicked();
    void on_btnSink3_clicked();
    void on_btnSink4_clicked();
    void on_btnSink5_clicked();
    void on_btnSink6_clicked();
    /* BEDS */
    void on_btnBabyBed_blue_clicked();
    void on_btnBabyBed_yellow_clicked();
    void on_btnSingleBed1_blue_clicked();
    void on_btnSingleBed1_yellow_clicked();
    void on_btnSingleBed1_white_clicked();
    void on_btnSingleBed2_blue_clicked();
    void on_btnSingleBed2_green_clicked();
    void on_btnSingleBed2_purple_clicked();
    void on_btnKingBed1_lightblue_clicked();
    void on_btnKingBed1_lightred_clicked();
    void on_btnKingBed1_white_clicked();
    void on_btnKingBed2_lightred_clicked();
    void on_btnKingBed2_white_clicked();
    /* ELECTRONIC DEVICES */
    void on_btnFridge_dark_clicked();
    void on_btnFridge_light_clicked();
    void on_btnRefrigerator_clicked();
    void on_btnWashingMachine_grey_clicked();
    void on_btnWashingMachine_white_clicked();
    void on_btnMicrowave_clicked();
    void on_btnVent_clicked();
    void on_btnAirConditioner_clicked();
    void on_btnTV1_black_clicked();
    void on_btnTV1_white_clicked();
    void on_btnTV2_black_clicked();
    void on_btnTV2_white_clicked();
    void on_btnLaptopMac_clicked();
    void on_btnLaptop_black_clicked();
    void on_btnLaptop_white_clicked();
    void on_btnPC_clicked();
    void on_btnSpeakers1_black_clicked();
    void on_btnSpeakers1_brown_clicked();
    void on_btnSpeakers2_black_clicked();
    void on_btnSpeakers2_brown_clicked();
    /* BATHROOM */
    void on_btnBath1_dark_clicked();
    void on_btnBath1_light_clicked();
    void on_btnBath1_white_clicked();
    void on_btnBath2_clicked();
    void on_btnShower_clicked();
    void on_btnBathroomCabinet_clicked();
    void on_btnBathSink1_clicked();
    void on_btnBathSink2_clicked();
    void on_btnToilet1_clicked();
    void on_btnToilet2_white_clicked();
    void on_btnToilet2_grey_clicked();
    /* DOORS */
    void on_btnDoor1_clicked();
    void on_btnDoor2_clicked();
    void on_btnDoor3_clicked();
    void on_btnDoor4_clicked();
    void on_btnDoor5_clicked();
    void on_btnDoor6_clicked();
    /* OTHER */
    void on_btnCarpet1_dark_clicked();
    void on_btnCarpet1_brown_clicked();
    void on_btnCarpet1_blue_clicked();
    void on_btnCarpet1_purple_clicked();
    void on_btnCarpet2Col2_clicked();
    void on_btnCarpet2Col1_clicked();
    void on_btnCarpet2Col3_clicked();
    void on_btnPiano_black_clicked();
    void on_btnPiano_brown_clicked();
    void on_btnBenchPress_clicked();
    void on_btnExerciseBike_clicked();
    void on_btnIroning_white_clicked();
    void on_btnIroning_lightblue_clicked();
    void on_btnChristmasTree_clicked();
    void on_btnPlant_clicked();
    void on_btnBin_clicked();
    void on_btnShelf_dark_clicked();
    void on_btnShelf_light_clicked();
    void on_btnShelf_grey_clicked();
    void on_btnShelf_white_clicked();
    void on_btnFireplace_clicked();
    void on_btnLamp1_clicked();
    void on_btnLamp2_clicked();
    void on_btnLamp3_clicked();
    void on_btnBooks_clicked();
    void on_btnBowl_clicked();
    void on_btnDuckie_clicked();
    void on_btnCat_clicked();
};

#endif // TEMPLATE_WINDOW_HPP

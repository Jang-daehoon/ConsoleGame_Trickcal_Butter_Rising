#include "GameManager.h"

GameManager::GameManager()
{
    curGameStage = 0;
    lastGameStage = 10;
    curBattleStage = 0;
    lastBattleStage = 10;
}

GameManager* GameManager::getInstance()
{
    // �ν��Ͻ��� nullptr�� ��쿡�� ���� ����
    if (instance == nullptr)
    {
        instance = new GameManager();
    }
    return instance;
}

//���� ȭ��
void GameManager::StartScreen()
{

    std::cout << R"(
                                .!.....,-,..:~    
              .:!!:;;*-         !--,~;!!;!!!.*    
            ,;:,     .;;    ~:  !-,;!.      !*    
          .!~   . ,~:;;::;;;.,!~:;-!        ,.    
        .!~    -;:.      .!    :-:!;.             
       ;~   .-:.     -~::!    .~~,.,:!:           
    .!;.  .-:  .  .!!~. ;    .;;!,;.~;!!!,        
 .:!:....,:- .  .~,,,-:!.    .-~ ~~~.    ::       
!!, ....:; ....      ..!     .;  ;;:.     !*.,:~-.
......,;-...-,.....-~.,!..,~;:,;;-..     -~.~-,,-~
!.,,,-;,..-~.....-:.  .-;:~, ....;       ;:....  .
!-,,:; ..:-.....-;.   ...   .....;-     ~:.:-...  
:-,~; ..;~......;..       .......,;.   -;:~ :~... 
 !~; ..~!......;,.................,;,.~;..,!.:-...
 ,* ...!.......;,,,,,,,,,...........;;~ ....:,:...
  ;-..!,.....,-;,,,,,,,,,,,,,................:-;,.
   ;.,!...,,,,~;:!!!:,~,,,,,,,,,....~.........:;,:
   !.-;..,,,,,!*~,,,~!:,,,-,,,,,,,,.:........  ;-,
   !-;:~:;-,-!~!;::;;!:-,------,,,,~~.......   -..
,  !:     !:;..!,,,,,-;,,,------,,,:~,...... . ,,.
!-~~       ;.~!:~,,,,,;,,,,,,,---,,;-,,..... ...~.
!!!        -,;!!:-,,,,:~,,,,,,,,,--!~,,,.... .. ;.
!!.         !!!;!!!~,,,!,,,,,,,,,,-~;,,,,... .. ;.
!;          :;;!!!!*;~~!;.,,,,,,,,~~*!;-,,......!,
!:          .!:--!*!*,-,::,,,,,,,,~!:,-;~,,.....;,
!-             :;;,!!:...:!,,,,,,,--,*;,;,,,....!,
!.            ;;~~!,*;  ..-*;,...,,;.:-!~:,,....!,
*            ;:---~!-!    ..~;!!;!;:-,:-;;-,,...:,
*            ;-----!,       ....,!*- :;--:,,,..-~,
;           ,-.,---;~         :*!!!!!~.;~,,,,...:,
!           ~,...- --        ;;;!!!!!!*~;:,,,,..;,
;           ;..... :.        ;~,..-::!!!;~!,,,...;
;           :,.....;              :;-.*!!-.;!-~-~~
;           -,   .:~            ~!--:!,*!!..---,,.
!            ;.  -;            ~!-----!,**..--,...
!            .;!;=             *------:,!*- :-....
*                             ~:..,----~:*~ !-....
*                             :-..... .-:*,-:.....
*.                ~   ,       ;,..... ,--; *......
*~                .!:;;;;:    -~.   ..*   ~-......
!*                  ;::~:;~    *~!;:~:-  ,:.......
**.                 !:    ~     ,       ~;........
*!;                 :     ;          .-!~......,..
*!*:                ,;   ,~         :~-.......;,..
*!!*.                -;--:           ~;,.~;~~;;-,.
!!!!!-                 ,               -!- -;;.~;;
!!!!!*:                                :.        -
**!**!**,                             .:          
!*!**!!!*!;-...             .      .,,~, ,,.     ,
*!**!!!*!!*****!::~~::;;;!!****!!!!*!!;!-:!;~,,,-:
)" << std::endl;

    MoveCursor::getInstance()->GotoXY(50, 0); std::cout << "������������������������" << std::endl;

    MoveCursor::getInstance()->GotoXY(60, 4); std::cout << " ��Ʈ���� ���� Ű����" << std::endl;

    MoveCursor::getInstance()->GotoXY(50, 9); std::cout << "������������������������" << std::endl;
    MoveCursor::getInstance()->GotoXY(65, 10); std::cout << "�� ���� TMI ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 12); std::cout << "����: ���΢�";
    MoveCursor::getInstance()->GotoXY(50, 14); std::cout << "�� ���Ͱ� �����ϴ� �� ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 16); std::cout << "�� �� ģ�� ��ͱ�" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 17); std::cout << "�� ������ �ڽŰ� ����ִ� ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 18); std::cout << "�� �ε巯�� ����" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 19); std::cout << "�� ������ �ڽ��� �Ӹ��� ���ٵ�� �ִ� ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 21); std::cout << "�� �Ⱦ��ϴ� �� ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 23); std::cout << "�� �ڽ��� ����" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 24); std::cout << "�� ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 25); std::cout << "�� ������ �ڽ��� ����ī�带 ������ ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 27); std::cout << "����̡� " << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 29); std::cout << "���ڹ̿� ���� ��⡻" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 30); std::cout << "�������� ���� ����α⡻" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 32); std::cout << "������������������������" << std::endl;

    MoveCursor::getInstance()->GotoXY(66, 36); std::cout << "�� �α��� (1) ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(65, 39); std::cout << "�� ȸ�� ���� (2) ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(65, 42); std::cout << "�� ���� ���� (3) ��" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 47); std::cout << "������������������������" << std::endl;
}

void GameManager::GrowthInterface()
{
    std::cout << R"(

  ..           ,.                                 
,~,.          ,,-,                                
:            .-  ~.                ,,,.           
~:~.       -!;:,.,.               -,...           
,;:,     ,:!:;;!,..     ..,-, .  .~..,,,.         
!;:~.   ,;;- ~;:....,-,,.,.   .,~~-.,-,,--        
;-  .  .!;,  -;,.,,--.,,,,   .  ..,.,.    .       
-,     ;;.  ,-.--,.---,..    .. .      .          
 :   .-,   -~,-,..,.. ...    ,  ,.     ,.         
,:-      .~--.-........,. .,--.,      ..  .      .
~ ,~---~-~,-.-..........,,,...-,,    .. .  ,-.    
. ,.~. .,.-.-...................-,  .... . ..     
,:!;-  -.-.,.....-,..............,--,.... .       
-;,;;-,.-......,..,,..,...................,.      
  -,;..- .....-----,,,-.,,,,,,..............      
 ,.;,.,. .......,.-,,,-.,,,,,,,--,-........ ..    
 -- -.- .,,.,.,,, .-,,,,,,,,,,,-,,.-,......... .. 
 ,  .-...,.,,,-,.. .,--~,,,,,,,,,,-,-,.......,....
.~-.,-....--:~....,.   .-,,,,,,,,,-~:-.......,. ..
 ~- -,....-.:~~~~--     ..--,--~~,~,,,.......-...,
.-. ,,....: ~~,. ,-~       ...  ..--,,,.....,-....
:,  .,...-,-:.   ~--~       .~-,~-.:,,,,....-,...,
     -...: ~   ,;~~-.       .~~~:;:,:-,,,...-,,.,,
     .-..;    -~---:       .-.  ..::~~~-,,...~~,,-
     .-,.~   ,~,,. ~          .... :;..~~~:::~,,,,
    ,. .,,   :.... -         ~~~~~, ;~  .~--,,,,,,
   ..       .~.  .-.        ~-----:.-:  .~,,,,,,,,
   ,         ~::;~:        --.,,--~..~  .-,,,,,,,,
   .                       :...., ,. -  ---,,,,,,,
~  .               -      .~..... -.   ,~,,,,,,-,,
-. ,              ,!*~,..  ~~. ...~   .:,,,,,,,~,,
.- ,.             .!!!~~-   .,:..,~  ,:,,,,,,,--,,
.~. -             .!~  ,.,    .:~: .-:,,,,,,,~-,,,
.,: .,             ~     -      .  ,:-,,,,-:~-,,,,
.,-, ,-            ,.    -          ,:::::~,,,,,,,
.,,:  ,~            -,  ,.          ~,,.,,,,,,,,,,
.,,,:  .:,           ,--.          ~....,,,,,,,,,,
.,,,:, .-,~.                      -,...,,,,,,,,,-,
,.,,::.,. .~-.                    ~...,,,,,,,,,,:,
~.,,:,~~  ,..-~~.                ~...,,,,,,,,,,:,,
;-,,~,,~  .---~!!~,--           .,..,,,,,,,,,,~-,,
:-~::-,, .-.-~,;!-~:.~~-,,.     .,.,,,,,,,,,,~~,,,
:----.-..,   ~-;;;-: ~:;;;:~:;;;:,.,,,,,,,,,~-,,,,
~----~. ~     ;:;-~,,:,,,,::~,,,~,,,,,,,,,-~-,,,,,
,----~~~      .:;.-::-.,~-,.~-,,~,,,,,,,,,,-,,,,,,
,------,     .-:;,---~~-,,,,~~,,~-,,,,,,,,--,,,,,,
.~-----      , :;~. .,--,.-~ .:--:-,,,,,,,--,,,,,,
;!:---::-..,-. :;:,.    ~-- ..-::;:,,,,,,--:,,,,,,
:::;~~,.--~--~,:;!.     ~-   .-,. .:-,,,,:,~~,,,,,
::::~: ,     ..-;;.    ,~     :..  .~-,,,::::-,,,,

)" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 0); std::cout << "������������������������" << std::endl;

    MoveCursor::getInstance()->GotoXY(60, 1); std::cout << " ��Ʈ���� ���� Ű����" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 4); RandomDialog();

    MoveCursor::getInstance()->GotoXY(50, 9); std::cout << "������������������������" << std::endl;

    myplayer.CharacterInfo();   //ĳ���� ���� ���

    MoveCursor::getInstance()->GotoXY(50, 32); std::cout << "������������������������" << std::endl;
    
    MoveCursor::getInstance()->GotoXY(50, 47); std::cout << "������������������������" << std::endl;
}

void GameManager::SelectGrowEvent()
{
    //1, 2, 3 ���� ���� �ۼ�
    int selectEvent = 0;
    while (myplayer.GetCurCost() > 0)
    {
        MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "1. � ������ �ϰԵɱ�?";
        MoveCursor::getInstance()->GotoXY(50, 38); std::cout << "2. ������ ��� ���� �ñ�����?!";
        MoveCursor::getInstance()->GotoXY(50, 41); std::cout << "3. ������ �鸸���ڵ� �� �� �־�?!";
        MoveCursor::getInstance()->GotoXY(50, 44); std::cout << "4. ����";
        
        MoveCursor::getInstance()->GotoXY(50, 46); std::cout << "�ൿ�� ������!!: "; std::cin >> selectEvent;

        switch (selectEvent)
        {
        case 1:
            system("cls");
            GrowthInterface();
            //Cost ����
            myplayer.usedCurCost();
            randomEvent.eventSet(); //���� �̺�Ʈ ���
            Sleep(300);    //0.3�ʴ��
            system("cls");
            GrowthInterface();


            break;
        case 2:
            system("cls");
            GrowthInterface();
            randomEvent.eventSet(); //���� �̺�Ʈ ���
            //Cost ����
            myplayer.usedCurCost();
            Sleep(300);    //0.3�ʴ��
            system("cls");
            GrowthInterface();

            break;
        case 3:
            system("cls");
            GrowthInterface();
            randomEvent.eventSet(); //���� �̺�Ʈ ���
            //Cost ����
            myplayer.usedCurCost();
            Sleep(300);    //0.3�ʴ��
            system("cls");
            GrowthInterface();

            break;

        default:
            std::cout << "��ȿ���� ���� �����Դϴ�.\n";
            Sleep(200);    //0.5�ʴ��
            system("cls");
            GrowthInterface();
            break;
        }
    }
    // Cost�� 0�� �� ó��
    system("cls");
    GrowthInterface();
    SetCurGameStage();  //���� �������� ++
    MoveCursor::getInstance()->GotoXY(65, 39); std::cout << "�����ͷ� �̵���";
    Sleep(3000);    //3�� ���
 
}

//����ȭ��
void GameManager::BattleInterface()
{
    system("cls");
    std::cout << "����ȭ�� ���" << std::endl;
    myplayer.CharacterBattleInfo();
    newEnemy.CharacterInfo();
    while (true)
    {
        //���� ����
        BattleSelect();
        BattleInterface();
        if (myplayer.getCurHp() <= 0)
        {
            std::cout << "�й�! �ݼ��� �������!" << std::endl;
            break;
        }
        else if (newEnemy.getCurHp() <= 0)
        {
            std::cout << "�¸�! ���� ���������� �̵��մϴ�!" << std::endl;
            SetCurGameStage();  //�������� ����
            //����, ���� Cost �ʱ�ȭ
            myplayer.initCurCost();
            myplayer.InitCurBattleCost();
        }
    }

}

//���� �ൿ ����
void GameManager::BattleSelect()
{
    int battleSelect;
    MoveCursor::getInstance()->GotoXY(0, 41); std::cout << "���������������������������������������������������";
    MoveCursor::getInstance()->GotoXY(0, 42); std::cout << "1. ����(Battle Cost 1 �Ҹ�)��";
    MoveCursor::getInstance()->GotoXY(30, 42); std::cout << "2. ���� ȹ��(BattleCost 1 �Ҹ�)  ��";
    MoveCursor::getInstance()->GotoXY(65, 42); std::cout << "3.��ų(BattleCost 5 �Ҹ� + MaxMana)";
    MoveCursor::getInstance()->GotoXY(0, 43); std::cout << "���������������������������������������������������";

    MoveCursor::getInstance()->GotoXY(0, 47); std::cout << "���������������������������������������������������";
    
    MoveCursor::getInstance()->GotoXY(0, 45); std::cout << "�����ൿ ����: "; std::cin >> battleSelect;
    switch (battleSelect)
    {
    case 1:
        myplayer.attack();
        myplayer.UsedBattleCost();
        myplayer.SetMana(); //���� �� ���� 5ȸ��
        break;
    case 2:
        std::cout << "���带 ȹ���߽��ϴ�." << std::endl;
        myplayer.UsedBattleCost();
        Sleep(1000);
        break;
    case 3:
        if (myplayer.getCurBattleCost() == myplayer.GetBattleCost() && myplayer.GetMana() == myplayer.GetMaxMana())
        {
            std::cout << "�����ö���! ��ų�� ����Ͽ����ϴ�!";
            myplayer.UsedMana();
            myplayer.UsedSkillCost();
            Sleep(1000);
        }
        else
            std::cout << "���� �Ǵ� Cost�� �����մϴ�." << std::endl;

        break;
    default:
        std::cout << "�ٽ� �Է��ϼ���" << std::endl;
        system("cls");
        BattleInterface();
        break;
    }
    //���� ����Ǿ� BattleCost ȸ��
    if (myplayer.getCurBattleCost() == 0)
    {
        //���� �ൿ
        newEnemy.attack();
        myplayer.InitCurBattleCost(); 
    }
    Sleep(1500);
    system("cls");
}



void GameManager::RandomDialog()
{
    srand(static_cast<unsigned int>(time(0)));
    // 1���� 3������ ���� ���� ����
    int randomValue = rand() % 3 + 1; // 1, 2, 3 �� �ϳ��� ��

    switch (randomValue)
    {
    case 1:
        //std::cout << RanDialog << std::endl;
        std::cout << "���ִ� ģ���� �ʹ� ���ƿ�!";
        break;
    case 2:
        std::cout << "���ִ� �ݰ�����! ���� �� �����̸� �ǵ��� ������!";
        break;
    case 3:
        std::cout << "���ִ�!! ��å ���� �ſ���? ���� ����! ����!";
        break;
    }
}

void GameManager::GameExit()
{
    exit(0);
}

void GameManager::GameMenuSelect()
{
    int select = 0;
    std::cin >> select;

    switch (select) {
    case 1:
        Login();
        break;
    case 2:
        Register();
        break;
    case 3:
        GameExit();
        break;
    default:

        std::cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << std::endl;

        Sleep(500);    //0.5�ʴ��
        system("cls");
        StartScreen();
        GameMenuSelect();    //����Լ�
    }
}

void GameManager::Login()
{
    //�ӽ� ��·���
    std::cout << "�α����Ͽ����ϴ�.";
}

void GameManager::Register()
{
    //�ӽ� ��� ����
    std::cout << "ȸ�������Ͽ����ϴ�.";
}

//getter
int GameManager::GetCurGameStage()
{
    return curGameStage;
}

int GameManager::GetLastGameStage()
{
    return lastGameStage;
}

int GameManager::GetCurBattleStage()
{
    return curBattleStage;
}

int GameManager::GetLastBattleStage()
{
    return lastBattleStage;
}

//setter
void GameManager::SetCurGameStage()
{
    curGameStage++;
}

void GameManager::SetCurBattleStage()
{
    curBattleStage++;
}

//�ܺο��� �����ϴ� ������ ���� ��������� �ʱ�ȭ, �޸� ������ ���ؼ��̴�.
// ��� �ν��Ͻ����� ������ ������ ��ŭ ������ �ʱ�ȭ �Ҷ� �ܺο��� �ѹ��� �����ؾ��Ѵ�.
// ���ο��� �ʱ�ȭ�ϸ� �� �ν��Ͻ����� �ٸ� ���� ������ �Ǿ� �̱��� ������ Ư���� �������.
// �޸� ���� -> ���α׷��� ������ �ϳ��� �����ؾ��ϹǷ� �ܺο��� �ʱ�ȭ�ؼ� �ν��Ͻ� ����
// �� ������ �޸𸮸� ȿ�������� ����ϵ��� �����ش�.
// �ʱ�ȭ
GameManager* GameManager::instance = nullptr;
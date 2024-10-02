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
    // 인스턴스가 nullptr일 경우에만 새로 생성
    if (instance == nullptr)
    {
        instance = new GameManager();
    }
    return instance;
}

//시작 화면
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

    MoveCursor::getInstance()->GotoXY(50, 0); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;

    MoveCursor::getInstance()->GotoXY(60, 4); std::cout << " ★트릭컬 버터 키우기★" << std::endl;

    MoveCursor::getInstance()->GotoXY(50, 9); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
    MoveCursor::getInstance()->GotoXY(65, 10); std::cout << "♪ 버터 TMI ♪" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 12); std::cout << "종족: 수인♣";
    MoveCursor::getInstance()->GotoXY(50, 14); std::cout << "♥ 버터가 좋아하는 것 ♥" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 16); std::cout << "♥ 새 친구 사귀기" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 17); std::cout << "♥ 누군가 자신과 놀아주는 것" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 18); std::cout << "♥ 부드러운 과자" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 19); std::cout << "♥ 누군가 자신의 머리를 쓰다듬어 주는 것" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 21); std::cout << "※ 싫어하는 것 ※" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 23); std::cout << "※ 자신의 꼬리" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 24); std::cout << "※ 귤" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 25); std::cout << "※ 누군가 자신의 옐로카드를 꺼내는 것" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 27); std::cout << "『취미』 " << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 29); std::cout << "『코미와 같이 놀기』" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 30); std::cout << "『간식을 땅에 묻어두기』" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 32); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;

    MoveCursor::getInstance()->GotoXY(66, 36); std::cout << "▶ 로그인 (1) ◀" << std::endl;
    MoveCursor::getInstance()->GotoXY(65, 39); std::cout << "▶ 회원 가입 (2) ◀" << std::endl;
    MoveCursor::getInstance()->GotoXY(65, 42); std::cout << "▶ 게임 종료 (3) ◀" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 47); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
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
    MoveCursor::getInstance()->GotoXY(50, 0); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;

    MoveCursor::getInstance()->GotoXY(60, 1); std::cout << " ★트릭컬 버터 키우기★" << std::endl;
    MoveCursor::getInstance()->GotoXY(50, 4); RandomDialog();

    MoveCursor::getInstance()->GotoXY(50, 9); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;

    myplayer.CharacterInfo();   //캐릭터 스텟 출력

    MoveCursor::getInstance()->GotoXY(50, 32); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
    
    MoveCursor::getInstance()->GotoXY(50, 47); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
}

void GameManager::SelectGrowEvent()
{
    //1, 2, 3 선택 질문 작성
    int selectEvent = 0;
    while (myplayer.GetCurCost() > 0)
    {
        MoveCursor::getInstance()->GotoXY(50, 35); std::cout << "1. 어떤 성장을 하게될까?";
        MoveCursor::getInstance()->GotoXY(50, 38); std::cout << "2. 누르면 어떻게 될지 궁금하지?!";
        MoveCursor::getInstance()->GotoXY(50, 41); std::cout << "3. 누르면 백만장자도 될 수 있어?!";
        MoveCursor::getInstance()->GotoXY(50, 44); std::cout << "4. 상점";
        
        MoveCursor::getInstance()->GotoXY(50, 46); std::cout << "행동을 선택해!!: "; std::cin >> selectEvent;

        switch (selectEvent)
        {
        case 1:
            system("cls");
            GrowthInterface();
            //Cost 차감
            myplayer.usedCurCost();
            randomEvent.eventSet(); //랜덤 이벤트 출력
            Sleep(300);    //0.3초대기
            system("cls");
            GrowthInterface();


            break;
        case 2:
            system("cls");
            GrowthInterface();
            randomEvent.eventSet(); //랜덤 이벤트 출력
            //Cost 차감
            myplayer.usedCurCost();
            Sleep(300);    //0.3초대기
            system("cls");
            GrowthInterface();

            break;
        case 3:
            system("cls");
            GrowthInterface();
            randomEvent.eventSet(); //랜덤 이벤트 출력
            //Cost 차감
            myplayer.usedCurCost();
            Sleep(300);    //0.3초대기
            system("cls");
            GrowthInterface();

            break;

        default:
            std::cout << "유효하지 않은 선택입니다.\n";
            Sleep(200);    //0.5초대기
            system("cls");
            GrowthInterface();
            break;
        }
    }
    // Cost가 0일 때 처리
    system("cls");
    GrowthInterface();
    SetCurGameStage();  //성장 스테이지 ++
    MoveCursor::getInstance()->GotoXY(65, 39); std::cout << "줘팸터로 이동중";
    Sleep(3000);    //3초 대기
 
}

//전투화면
void GameManager::BattleInterface()
{
    system("cls");
    std::cout << "전투화면 출력" << std::endl;
    myplayer.CharacterBattleInfo();
    newEnemy.CharacterInfo();
    while (true)
    {
        //전투 선택
        BattleSelect();
        BattleInterface();
        if (myplayer.getCurHp() <= 0)
        {
            std::cout << "패배! 반성문 써오세요!" << std::endl;
            break;
        }
        else if (newEnemy.getCurHp() <= 0)
        {
            std::cout << "승리! 다음 스테이지로 이동합니다!" << std::endl;
            SetCurGameStage();  //스테이지 증가
            //성장, 전투 Cost 초기화
            myplayer.initCurCost();
            myplayer.InitCurBattleCost();
        }
    }

}

//전투 행동 선택
void GameManager::BattleSelect()
{
    int battleSelect;
    MoveCursor::getInstance()->GotoXY(0, 41); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
    MoveCursor::getInstance()->GotoXY(0, 42); std::cout << "1. 공격(Battle Cost 1 소모)■";
    MoveCursor::getInstance()->GotoXY(30, 42); std::cout << "2. 쉴드 획득(BattleCost 1 소모)  ■";
    MoveCursor::getInstance()->GotoXY(65, 42); std::cout << "3.스킬(BattleCost 5 소모 + MaxMana)";
    MoveCursor::getInstance()->GotoXY(0, 43); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";

    MoveCursor::getInstance()->GotoXY(0, 47); std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
    
    MoveCursor::getInstance()->GotoXY(0, 45); std::cout << "전투행동 선택: "; std::cin >> battleSelect;
    switch (battleSelect)
    {
    case 1:
        myplayer.attack();
        myplayer.UsedBattleCost();
        myplayer.SetMana(); //공격 시 마나 5회복
        break;
    case 2:
        std::cout << "쉴드를 획득했습니다." << std::endl;
        myplayer.UsedBattleCost();
        Sleep(1000);
        break;
    case 3:
        if (myplayer.getCurBattleCost() == myplayer.GetBattleCost() && myplayer.GetMana() == myplayer.GetMaxMana())
        {
            std::cout << "버터플라이! 스킬을 사용하였습니다!";
            myplayer.UsedMana();
            myplayer.UsedSkillCost();
            Sleep(1000);
        }
        else
            std::cout << "마나 또는 Cost가 부족합니다." << std::endl;

        break;
    default:
        std::cout << "다시 입력하세요" << std::endl;
        system("cls");
        BattleInterface();
        break;
    }
    //턴이 종료되어 BattleCost 회복
    if (myplayer.getCurBattleCost() == 0)
    {
        //적의 행동
        newEnemy.attack();
        myplayer.InitCurBattleCost(); 
    }
    Sleep(1500);
    system("cls");
}



void GameManager::RandomDialog()
{
    srand(static_cast<unsigned int>(time(0)));
    // 1부터 3까지의 랜덤 값을 생성
    int randomValue = rand() % 3 + 1; // 1, 2, 3 중 하나의 값

    switch (randomValue)
    {
    case 1:
        //std::cout << RanDialog << std::endl;
        std::cout << "꾜주님 친구들 너무 좋아요!";
        break;
    case 2:
        std::cout << "꾜주님 반가워요! 제가 판 구덩이만 건들지 마세요!";
        break;
    case 3:
        std::cout << "꾜주님!! 산책 가는 거에요? 빨리 가요! 빨리!";
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

        std::cout << "잘못된 입력입니다. 다시 선택하세요." << std::endl;

        Sleep(500);    //0.5초대기
        system("cls");
        StartScreen();
        GameMenuSelect();    //재귀함수
    }
}

void GameManager::Login()
{
    //임시 출력로직
    std::cout << "로그인하였습니다.";
}

void GameManager::Register()
{
    //임시 출력 로직
    std::cout << "회원가입하였습니다.";
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

//외부에서 선언하는 이유는 정적 멤버변수의 초기화, 메모리 관리를 위해서이다.
// 모든 인스턴스에서 접근이 가능한 만큼 변수를 초기화 할때 외부에서 한번만 수행해야한다.
// 내부에서 초기화하면 각 인스턴스마다 다른 값을 가지게 되어 싱글톤 패턴의 특성이 사라진다.
// 메모리 관리 -> 프로그램의 수명동안 하나만 존재해야하므로 외부에서 초기화해서 인스턴스 관리
// 이 패턴은 메모리를 효율적으로 사용하도록 도와준다.
// 초기화
GameManager* GameManager::instance = nullptr;
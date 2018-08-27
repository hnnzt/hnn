#include <time.h>   /* 包含设定随机数种子所需要的time()函数 */
#include <stdio.h>  /* 包含C的IO读写功能 */
#include <stdlib.h> /* 包含C标准库的功能 */

#ifdef _WIN32

/* 包含Windows平台相关函数，包括控制台界面清屏及光标设定等功能 */
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <direct.h>
#include <Shlobj.h>

#else

/* 包含Linux平台相关函数，包括控制台界面清屏及光标设定等功能 */
#include <termio.h>
#include <unistd.h>
#include <bits/signum.h>
#include <signal.h>

#define KEY_CODE_UP    0x41
#define KEY_CODE_DOWN  0x42
#define KEY_CODE_LEFT  0x44
#define KEY_CODE_RIGHT 0x43
#define KEY_CODE_QUIT  0x71

struct termios old_config; /* linux下终端属性配置备份 */

#endif

static char config_path[4096] = { 0 }; /* 配置文件路径 */

static void init_game();    /* 初始化游戏 */
static void loop_game();    /* 游戏循环 */
static void reset_game();   /* 重置游戏 */
static void release_game(int signal); /* 释放游戏 */

static int read_keyboard();

static void move_left();  /* 左移 */
static void move_right(); /* 右移 */
static void move_up();    /* 上移 */
static void move_down();  /* 下移 */

static void add_rand_num();    /* 生成随机数，本程序中仅生成2或4，概率之比设为9:1 */
static void check_game_over(); /* 检测是否输掉游戏，设定游戏结束标志 */
static int get_null_count();   /* 获取游戏面板上空位置数量 */
static void clear_screen();    /* 清屏 */
static void refresh_show();    /* 刷新界面显示 */

static int board[4][4];     /* 游戏数字面板，抽象为二维数组 */
static int score;           /* 游戏得分 */
static int best;            /* 游戏最高分 */
static int if_need_add_num; /* 是否需要生成随机数标志，1表示需要，0表示不需要 */
static int if_game_over;    /* 是否游戏结束标志，1表示游戏结束，0表示正常 */
static int if_prepare_exit; /* 是否准备退出游戏，1表示是，0表示否 */

#include <time.h>   /* �����趨�������������Ҫ��time()���� */
#include <stdio.h>  /* ����C��IO��д���� */
#include <stdlib.h> /* ����C��׼��Ĺ��� */

#ifdef _WIN32

/* ����Windowsƽ̨��غ�������������̨��������������趨�ȹ��� */
#include <conio.h>
#include <windows.h>
#include <io.h>
#include <direct.h>
#include <Shlobj.h>

#else

/* ����Linuxƽ̨��غ�������������̨��������������趨�ȹ��� */
#include <termio.h>
#include <unistd.h>
#include <bits/signum.h>
#include <signal.h>

#define KEY_CODE_UP    0x41
#define KEY_CODE_DOWN  0x42
#define KEY_CODE_LEFT  0x44
#define KEY_CODE_RIGHT 0x43
#define KEY_CODE_QUIT  0x71

struct termios old_config; /* linux���ն��������ñ��� */

#endif

static char config_path[4096] = { 0 }; /* �����ļ�·�� */

static void init_game();    /* ��ʼ����Ϸ */
static void loop_game();    /* ��Ϸѭ�� */
static void reset_game();   /* ������Ϸ */
static void release_game(int signal); /* �ͷ���Ϸ */

static int read_keyboard();

static void move_left();  /* ���� */
static void move_right(); /* ���� */
static void move_up();    /* ���� */
static void move_down();  /* ���� */

static void add_rand_num();    /* ������������������н�����2��4������֮����Ϊ9:1 */
static void check_game_over(); /* ����Ƿ������Ϸ���趨��Ϸ������־ */
static int get_null_count();   /* ��ȡ��Ϸ����Ͽ�λ������ */
static void clear_screen();    /* ���� */
static void refresh_show();    /* ˢ�½�����ʾ */

static int board[4][4];     /* ��Ϸ������壬����Ϊ��ά���� */
static int score;           /* ��Ϸ�÷� */
static int best;            /* ��Ϸ��߷� */
static int if_need_add_num; /* �Ƿ���Ҫ�����������־��1��ʾ��Ҫ��0��ʾ����Ҫ */
static int if_game_over;    /* �Ƿ���Ϸ������־��1��ʾ��Ϸ������0��ʾ���� */
static int if_prepare_exit; /* �Ƿ�׼���˳���Ϸ��1��ʾ�ǣ�0��ʾ�� */

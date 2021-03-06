/*
 * Window XCreateSimpleWindow(
 *      Display *display, Window parent,
 *      int x, int y,
 *      unsigned int width, unsigned int height,
 *      unsigned int border_width, unsigned long border,
 *      unsigned long background);
 */

#include "tips.h"

void tips_XCreateSimpleWindow(void)
{
    TIPS_HEAD;

    //Display *display = XOpenDisplay(NULL);
    Display * display;
    if ((display = XOpenDisplay(NULL)) == NULL)
        TIPS_PERROR_AND_EXIT_FAILURE;

    int screen_number = DefaultScreen(display);
    int display_width = DisplayWidth(display, screen_number);
    int display_height = DisplayHeight(display, screen_number);

    Window win;
    XWindowAttributes *win_attr;
    int x = 0, y = 0;
    unsigned int width = display_width / 2;
    unsigned int height = display_height / 2;
    int border_width = 2;

    win = XCreateSimpleWindow(
        display, RootWindow(display, screen_number),
        x, y, width, height,
        border_width, BlackPixel(display, screen_number),
        WhitePixel(display, screen_number));

}

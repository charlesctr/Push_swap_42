# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    visu.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chcoutur <chcoutur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 11:50:59 by chcoutur          #+#    #+#              #
#    Updated: 2019/10/08 09:18:49 by chcoutur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env python3

from tkinter import *
import sys
import os
import subprocess
import time
import psutil

EXEC_PATH = r'../push_swap'

class PyVisu:
    def __init__(self, master):

        '''
        Set arguments of main page with set_w and set_h size
        Set path of push_swap executable
        Creation of two stack _a and _b
        Arg passed to push_swap are recovered by python script and set into
        self.stack_a | stack_b is empty
        Output of push_swap is recover in a list called self.commands
        Display speed is set by 1 / LEN_OF[stack_a]
        Set title of mainpage, and create the mainpage
        Split mainpage in underframe to display different info
        '''

        self.set_w = 800
        self.set_h = 1000
        self.i = 0
        dirname = os.path.dirname(os.path.abspath(__file__))
        PUSH_PATH = os.path.join(dirname, EXEC_PATH)
        self.stack_a = [int(val) for val in sys.argv[1:]]
        self.first_stack = self.stack_a[:]
        self.stack_b = []
        self.commands = subprocess.check_output([PUSH_PATH] + sys.argv[1:],
        stderr=subprocess.STDOUT,timeout = 15).splitlines()
        if len(self.stack_a) != 0:
            self.speed = 1 / len(self.stack_a)
        else:
            self.speed = 0
        self.master = master
        master.title("Push_Swap || Visualizer")
        self.mainframe = Frame(master)
        self.mainframe.pack(fill=BOTH)
        self.sort_frame = Canvas(self.mainframe, width = self.set_w,
        height = self.set_h, highlightthickness=2, bg = "#292929")
        self.sort_frame.pack(side = RIGHT)
        self.hud_frame = Frame(self.mainframe,)
        self.hud_frame.pack(side = LEFT, fill= BOTH)
        self.listbox = Listbox(self.hud_frame, bg='#292929', fg='white',
        highlightthickness=2 ,font=("avenir medium oblique", 20))
        self.listbox.pack(fill=BOTH, expand=1, side = TOP)
        for command in self.commands:
            self.listbox.insert(END, command)
        self.info_frame=Frame(master, borderwidth = 1, bg = "#292929")
        self.info_frame.pack(side=BOTTOM, fill=X)
        self.data_frame=Frame(self.info_frame, highlightbackground="black",
        highlightcolor="black", highlightthickness=4)
        self.data_frame.pack(side=LEFT)
        self.perf_frame=Frame(self.info_frame, highlightbackground="black",
        highlightcolor="black", highlightthickness=4)
        self.perf_frame.pack(side=RIGHT)
        self.nb_move = Label(self.data_frame,
        text='Total move =\t' + str(len(self.commands)),
        font=("avenir black", 20))
        self.nb_move.pack(side=TOP)
        self.max_nb = Label(self.data_frame,
        text='Max value =\t' + str(max(self.stack_a)),
        font=("avenir black", 15))
        self.max_nb.pack(side=TOP)
        self.min_nb = Label(self.data_frame,
        text='Min value =\t' + str(min(self.stack_a)),
        font=("avenir black", 15))
        self.min_nb.pack(side=TOP)
        self.total_nb = Label(self.data_frame,
        text='Total value =\t' + str(len(self.stack_a)),
        font=("avenir black", 15))
        self.total_nb.pack(side=TOP)
        cpu = psutil.cpu_percent()
        ram = psutil.virtual_memory()[2]
        cores = psutil.cpu_count()
        self.cpu_perf = Label(self.perf_frame,
        text='Actual CPU usage (%) =\t' + str(cpu),font=("avenir black", 15))
        self.cpu_perf.pack(side=TOP)
        self.ram_perf = Label(self.perf_frame,
        text='Actual RAM usage (%) =\t' + str(ram), font=("avenir black", 15))
        self.ram_perf.pack(side=TOP)
        self.cores_perf = Label(self.perf_frame,
        text='Actual Cores usage (n) =\t' + str(cores),
        font=("avenir black", 15))
        self.cores_perf.pack(side=TOP)
        self.path_perf = Label(self.perf_frame,
        text='PATH =\t' + str(PUSH_PATH),
        font=("avenir black", 15))
        self.path_perf.pack(side=TOP)
        self.title_frame = Frame(self.info_frame,
        highlightbackground="black", highlightcolor="black",
        highlightthickness=4)
        self.title_frame.pack(side=TOP)
        self.title_main = Label(self.title_frame,
        text='./push_swap', font=("avenir black", 25))
        self.title_main.pack(side=TOP)
        self.display_value()
        self.start()

    '''
    Creation of destroy function to kill the process and the page at the end 
    by pressing <Escape> key
    '''

    def exit():
        root.destroy()
    '''
    Display sort in real time in terms of the push_swap output
    '''

    def start_commands(self, command):
        if command == b'sa' and len(self.stack_a) >= 2:
            self.stack_a[0], self.stack_a[1] = self.stack_a[1], self.stack_a[0]
        if command == b'sb' and len(self.stack_b) >= 2:
            self.stack_b[0], self.stack_b[1] = self.stack_b[1], self.stack_b[0]
        if command == b'ss':
            if (len(self.stack_a) >= 2):
                self.stack_a[0], self.stack_a[1] = self.stack_a[1],
                self.stack_a[0]
            if (len(self.stack_b) >= 2):
                self.stack_b[0], self.stack_b[1] = self.stack_b[1],
                self.stack_b[0]
        if command == b'ra' and len(self.stack_a) >= 2:
            self.stack_a.append(self.stack_a[0])
            del self.stack_a[0]
        if command == b'rb' and len(self.stack_b) >= 2:
            self.stack_b.append(self.stack_b[0])
            del self.stack_b[0]
        if command == b'rr':
            if (len(self.stack_a) >= 2):
                self.stack_a.append(self.stack_a[0])
                del self.stack_a[0]
            if (len(self.stack_b) >= 2):
                self.stack_b.append(self.stack_b[0])
                del self.stack_b[0]
        if command == b'rra' and len(self.stack_a) >= 2:
            self.stack_a = [self.stack_a[-1]] + self.stack_a
            del self.stack_a[-1]
        if command == b'rrb' and len(self.stack_b) >= 2:
            self.stack_b = [self.stack_b[-1]] + self.stack_b
            del self.stack_b[-1]
        if command == b'rrr':
            if (len(self.stack_a) >= 2):
                self.stack_a = [self.stack_a[-1]] + self.stack_a
                del self.stack_a[-1]
            if (len(self.stack_b) >= 2):
                self.stack_b = [self.stack_b[-1]] + self.stack_b
                del self.stack_b[-1]
        if command == b'pa' and len(self.stack_b) >= 1:
            self.stack_a = [self.stack_b[0]] + self.stack_a
            del self.stack_b[0]
        if command == b'pb' and len(self.stack_a) >= 1:
            self.stack_b = [self.stack_a[0]] + self.stack_b
            del self.stack_a[0]
        return self.stack_a, self.stack_b

    '''
    Display each rectangle, with specific position in terms of the len of
    stack_a + stack_b
    stack_a is RED 
    stack_b is BLUE
    '''

    def display_value(self):
        vi = 0
        ww = (self.set_w - 50)
        wh = (self.set_h - 50)
        hw = ww / 2
        hm = len(self.stack_a) + len(self.stack_b)
        mx, mn = (0, 0)
        if (hm != 0):
            mx = max(self.stack_a + self.stack_b)
            mn = min(self.stack_a + self.stack_b)
        rects = []
        if len(self.stack_a) > 0:
            a_val = [(val - mn) / (mx - mn) for val in self.stack_a]
            for vala in a_val:
                rects.append(self.sort_frame.create_rectangle(0, vi,
                15 + vala * (hw - 100), vi + wh / hm, fill="red",
                outline="white"))
                vi += wh / hm
        vi = 0
        if len(self.stack_b) > 0:
            b_val = [(val - mn) / (mx - mn) for val in self.stack_b]
            for valb in b_val:
                rects.append(self.sort_frame.create_rectangle(hw, vi,
                hw + 150 + valb * (hw - 100), vi + wh / hm,
                fill ="blue", outline="white"))
                vi += wh / hm
    '''
    Main function with loop from 0 to number of movement of push_swap
    - Display actual move
    - Kill all rectangle
    - Create new rectangle
    - Display new rectangle
    - Create scroll on Y axe to listbox on the left if there is too much text
    - Update frame with new arguments
    '''
    def start(self):
        while self.i < len(self.commands):
            if self.speed != 0:
                while self.i < len(self.commands):
                    self.listbox.activate(self.i)
                    self.sort_frame.delete("all")
                    self.stack_a, self.stack_b = self.start_commands(
                            self.commands[self.i])
                    self.display_value()
                    time.sleep(2 * self.speed)
                    self.sort_frame.update()
                    self.listbox.yview_scroll(1, 'units')
                    self.i += 1
                time.sleep(0.3)
                self.sort_frame.update()

my_window=Tk()
my_window.resizable(False, False)
my_window.bind("<Escape>", exit)
gui = PyVisu(my_window)
my_window.mainloop()

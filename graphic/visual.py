#!/usr/local/bin/python3

from tkinter import *
import	re
import time
import subprocess

class	Square:
	def __init__(self, sq, state):
		self.sq = sq
		self.state = state

	def __str__(self):
		return str(self.sq)

class	Coords:
	def __init__(self, x, y, player, zone, score):
		self.x = x
		self.y = y
		self.player = player
		self.zone = zone
		self.score = score

global lock

lock = 0

start_pos = {
	0 : [[8, 2], [12, 14], [15, 17], [30, 60]],
	1 : [[3, 3], [19, 32], [24, 40], [50, 80]],
	2 : [[69, 70], [29, 30], [100, 99], [70, 100]]
}


def get_input(tetraminoTable):

	b = []
	pos = Coords(0, 0, 0, 0, 0)
	for line in sys.stdin:
		if (line[:5] == "Piece" or b):
			b.append(line)
		if (line[0] == '='):
			b.append(line)
			if (len(b) == 2):
				break
		if (line[0] == '<'):
			pos.y, pos.x = list(map(int, re.findall(r"\d+", line)))
			pos.player = 'O' if line.find('O') != -1 else 'X' 
			break
	if (b and '=' in b[0]):
		pos.score = list(map(int, re.findall(r"\d+", "".join(b))))
	pos.zone = list(map(lambda x: x[: len(x) - 1],b[1:len(b) - 1]))
	return pos

def generate_table(frame, height, width, pos):
	x = pos[2][1]
	y = pos[2][0]
	height = height / y
	width = width / x
	game_map = [[0 for i in range(x)] for i in range(y)]
	for i in range(y):
		for j in range(x):
			game_map[i][j] = Square(frame.create_rectangle(j * width + 2, i * height + 2,
								(j + 1) * width, (i + 1) * height, fill="#969696"), "empty")

	game_map[pos[0][0]][pos[0][1]].state = "p1"
	game_map[pos[1][0]][pos[1][1]].state = "p2"
	frame.itemconfig(game_map[pos[0][0]][pos[0][1]], fill="#beff00")
	frame.itemconfig(game_map[pos[1][0]][pos[1][1]], fill="#ff6464")
	return game_map

def	show_score(gameOptions, score):
	
	score1Label = Label(gameOptions, text="{}".format(score[0]),
						font="Impact 30", fg="#beff00", bg="#d3d3d3")
	score2Label = Label(gameOptions, text="{}".format(score[1]), 
						font="Impact 30", fg="#ff6464", bg="#d3d3d3")
	score1Label.place(x=180, y=10)
	score2Label.place(x=580, y=10)


def restart_map(argv, root):
	subprocess.Popen("python3 dialog.py " + argv[4] + " " + argv[2] + " " + argv[3] + " " + argv[1],
					stdin=subprocess.PIPE, shell=True)
	root.destroy()

def stop_map(startButton, stopButton):
	global lock
	stopButton.place_forget()
	startButton.place(x=330, y=85)
	lock = 1
	

def update_map(game_map, frame, gameOptions, restartButton, startButton, n, stopButton):

	global lock
	pos = get_input(restartButton)
	if (n == 1):
		startButton.place_forget()
		stopButton.place(x=330, y=85)
		lock = 0
	if (pos.score):
		show_score(gameOptions, pos.score)
		startButton.place_forget()
		stopButton.place_forget()
		restartButton.place(x=330, y=85)
		return
	if (not (pos.x == 0 and pos.y == 0)):
		color = "#beff00" if pos.player == "O" else "#ff6464"
		neg_color = "#beff00" if pos.player == "X" else "#ff6464"
		for i in range(len(pos.zone)):
			for j in range(len(pos.zone[i])):
				if (pos.zone[i][j] != '.' and pos.y + i >= 0 and pos.y + i < len(game_map)
				and pos.x + j >= 0 and pos.x + j < len(game_map[i])):
					if (game_map[pos.y + i][pos.x + j].state != neg_color):
						game_map[pos.y + i][pos.x + j].state = color
						frame.itemconfig(game_map[pos.y + i][pos.x + j], fill=color)

	if (lock):
		restartButton.place(x=330, y=50)
	if (not lock):
		restartButton.place_forget()
		frame.after(50, update_map, game_map, frame, gameOptions,
						restartButton, startButton, 0, stopButton)

def init_window():
	root = Tk()
	root.title("Filler")
	root.geometry("904x1000+850+200")
	root.configure(bg = "#d3d3d3")

	n = int(sys.argv[1][-1])
	p1 = sys.argv[2][sys.argv[2].rfind("/") + 1: sys.argv[2].rfind(".")]
	p2 = sys.argv[3][sys.argv[3].rfind("/") + 1: sys.argv[3].rfind(".")]

	tableFrame = Canvas(root, height=700, width=900, bg="#d3d3d3", highlightthickness=2,
					highlightbackground="#EB2188", highlightcolor="#EB2188", bd=0)
	gameOptions = Frame(root, height=150, width=840, bg="#d3d3d3")

	game_map = generate_table(tableFrame, 700, 900, start_pos[n])

	restartButton = Button(gameOptions, text="Restart", font="Arial 20",
						width=10, height=1, highlightthickness=2, 
						command=lambda: restart_map(sys.argv, root),
						highlightbackground="#d3d3d3", highlightcolor="#EB2188")
	startButton = Button(gameOptions, text="Start", font="Arial 20",
						width=10, height=1, highlightthickness=2, 
						command=lambda: update_map(game_map, tableFrame, gameOptions, 
						restartButton, startButton, 1, stopButton),
						highlightbackground="#d3d3d3", highlightcolor="#EB2188")

	stopButton = Button(gameOptions, text="Stop", font="Arial 20",
						width=10, height=1, highlightthickness=2, 
						command=lambda: stop_map(startButton, stopButton),
						highlightbackground="#d3d3d3", highlightcolor="#EB2188")

	fillerFLabel = Label(root, text="F", font="Impact 80", fg="#8A2BE2", bg="#d3d3d3")
	fillerMainLaber = Label(root, text="iller", font="Impact 30", fg="#FF00FF", bg="#d3d3d3")
	player1Label = Label(gameOptions, text=p1, font="Impact 30", fg="#beff00", bg="#d3d3d3")
	player2Label = Label(gameOptions, text=p2, font="Impact 30", fg="#ff6464", bg="#d3d3d3")

	tableFrame.place(x=0, y=120)
	gameOptions.place(x=30, y=850)
	startButton.place(x=330, y=85)
	fillerFLabel.place(x=390, y=10)
	fillerMainLaber.place(x=425, y=61)
	player1Label.place(x=70, y=10)
	player2Label.place(x=630, y=10)
	root.mainloop()

if (len(sys.argv) == 5):
	init_window()
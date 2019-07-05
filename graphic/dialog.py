import subprocess
from tkinter import *
from tkinter.filedialog import askopenfilename
from tkinter import messagebox
import os



def run_table(player1Text, player2Text, mapText, root):
    p1 = player1Text.get('1.0', END)
    p2 = player2Text.get('1.0', END)
    game_map = mapText.get('1.0', END)
    if (len(p1) == 1 or len(p2) == 1 or len(game_map) == 1):
        messagebox.showinfo("!!!!!!!!!!", "Please input files")
    else:
        print("resources/filler_vm -f " + game_map + " -p1 " + p1 + "-p2 " + p2 + " | ./visual.py")
        subprocess.Popen("resources/filler_vm -f " + game_map[:-1] + " -p1 " + p1[:-1] + " -p2 " + p2[:-1] + " | ./visual.py",
                            stdin=subprocess.PIPE, shell=True)
        root.destroy()

def OpenFile(mainText):
    name = askopenfilename(initialdir=os.getcwd() + '/',
            title = "Choose a file.")
    
    # l = name.split('/')
    mainText.delete('1.0', END)
    mainText.insert(INSERT, name)

root = Tk()
root.title("Filler")
root.geometry("600x300+950+500")
root.configure(bg = "#d3d3d3")

player1Label = Label(root, text="Player 1", font="Impact 30", fg="#beff00", bg="#d3d3d3")
player2Label = Label(root, text="Player 2", font="Impact 30", fg="#ff6464", bg="#d3d3d3")
mapLabel = Label(root, text="Map", font="Impact 30", fg="#FF00FF", bg="#d3d3d3")

player1Text = Text(root, width=25, height=1, fg="#beff00", font="Impact 20")
player2Text = Text(root, width=25, height=1, fg="#ff6464", font="Impact 20")
mapText = Text(root, width=25, height=1, fg="#ff6464", font="Impact 20")


open1Button = Button(root, text="browse", font="Arial 20",
					width=7, height=1, highlightthickness=2,
                    command=lambda : OpenFile(player1Text),
				 	highlightbackground="#d3d3d3", highlightcolor="#EB2188")

open2Button = Button(root, text="browse", font="Arial 20",
					width=7, height=1, highlightthickness=2,
                    command=lambda : OpenFile(player2Text),
				 	highlightbackground="#d3d3d3", highlightcolor="#EB2188")

open3Button = Button(root, text="browse", font="Arial 20",
					width=7, height=1, highlightthickness=2,
                    command=lambda : OpenFile(mapText),
				 	highlightbackground="#d3d3d3", highlightcolor="#EB2188")

startButton = Button(root, text="Ok", font="Arial 20",
					width=7, height=1, highlightthickness=2,
                    command=lambda : run_table(player1Text, player2Text, mapText, root),
				 	highlightbackground="#d3d3d3", highlightcolor="#EB2188")
             
player1Label.place(x=10, y=35)
player2Label.place(x=10, y=90)
mapLabel.place(x=50, y=145)
player1Text.place(x=140, y=40)
player2Text.place(x=140, y=95)
mapText.place(x=140, y=150)
open1Button.place(x=450, y=35)
open2Button.place(x=450, y=90)
open3Button.place(x=450, y=145)
startButton.place(x=220, y=240)
root.mainloop()







# run = subprocess.Popen( "resources/filler_vm -f resources/maps/map00\
#                             -p1 ./nlavrine.filler -p2 resources/players/carli.filler |\
#                             ./visual.py",
#                             stdin=subprocess.PIPE, shell=True )
    				# command=lambda: update_map(game_map, tableFrame, gameOptions),
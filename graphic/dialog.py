import subprocess
from tkinter import *
from tkinter.filedialog import askopenfilename, askdirectory
from tkinter import messagebox
import os



def run_table(resource, player1Text, player2Text, mapText, root):
    res = resource.get('1.0', END)[:-1]
    p1 = player1Text.get('1.0', END)[:-1]
    p2 = player2Text.get('1.0', END)[:-1]
    game_map = mapText.get('1.0', END)[:-1]
    if (len(p1) == 0 or len(p2) == 0 or len(game_map) == 0):
        messagebox.showinfo("!!!!!!!!!!", "Please input files")
    else:
        try:
            subprocess.Popen(res + "/filler_vm -f " + game_map + " -p1 " + p1 + " -p2 " + p2 +\
                " | python3 visual.py " + game_map + " " + p1 + " " + p2 + " " + res
                , stdin=subprocess.PIPE, shell=True)
            root.destroy()
        except:
            messagebox.showinfo("!!!!!!!!!!", "Input correct files")

def OpenFolder(mainText):
    name = askdirectory(initialdir=os.getcwd() + '/',
                title="choose directory")
    mainText.delete('1.0', END)
    mainText.insert(INSERT, name)


def OpenFile(mainText):
    name = askopenfilename(initialdir=os.getcwd() + '/',
            title = "Choose a file.")
    mainText.delete('1.0', END)
    mainText.insert(INSERT, name)

def fill_Text(resourceText, player1Text, player2Text, mapText, argv):
    resourceText.insert(INSERT, argv[1])
    player1Text.insert(INSERT, argv[2])
    player2Text.insert(INSERT, argv[3])
    mapText.insert(INSERT, argv[4])

root = Tk()
root.title("Filler")
root.geometry("600x300+950+500")
root.configure(bg = "#d3d3d3")



resourceLabel = Label(root, text="Resource", font="Impact 25", fg="#beff00", bg="#d3d3d3")
player1Label = Label(root, text="Player 1", font="Impact 30", fg="#beff00", bg="#d3d3d3")
player2Label = Label(root, text="Player 2", font="Impact 30", fg="#ff6464", bg="#d3d3d3")
mapLabel = Label(root, text="Map", font="Impact 30", fg="#FF00FF", bg="#d3d3d3")

resourceText = Text(root, width=40, height=1, fg="#FF00FF", font="Impact 13")
player1Text = Text(root, width=40, height=1, fg="#beff00", font="Impact 13")
player2Text = Text(root, width=40, height=1, fg="#ff6464", font="Impact 13")
mapText = Text(root, width=40, height=1, fg="#FF00FF", font="Impact 13")

if (len(sys.argv) == 5):
    fill_Text(resourceText, player1Text, player2Text, mapText, sys.argv)

open1Button = Button(root, text="browse", font="Arial 20",
					width=7, height=1, highlightthickness=2,
                    command=lambda : OpenFolder(resourceText),
				 	highlightbackground="#d3d3d3", highlightcolor="#EB2188")

open2Button = Button(root, text="browse", font="Arial 20",
					width=7, height=1, highlightthickness=2,
                    command=lambda : OpenFile(player1Text),
				 	highlightbackground="#d3d3d3", highlightcolor="#EB2188")

open3Button = Button(root, text="browse", font="Arial 20",
					width=7, height=1, highlightthickness=2,
                    command=lambda : OpenFile(player2Text),
				 	highlightbackground="#d3d3d3", highlightcolor="#EB2188")

open4Button = Button(root, text="browse", font="Arial 20",
					width=7, height=1, highlightthickness=2,
                    command=lambda : OpenFile(mapText),
				 	highlightbackground="#d3d3d3", highlightcolor="#EB2188")



startButton = Button(root, text="Ok", font="Arial 20",
					width=7, height=1, highlightthickness=2,
                    command=lambda : run_table(resourceText, player1Text, player2Text, mapText, root),
				 	highlightbackground="#d3d3d3", highlightcolor="#EB2188")

resourceLabel.place(x=10, y=25)
player1Label.place(x=10, y=75)
player2Label.place(x=10, y=130)
mapLabel.place(x=50, y=185)
resourceText.place(x=140, y=33)
player1Text.place(x=140, y=83)
player2Text.place(x=140, y=138)
mapText.place(x=140, y=193)
open1Button.place(x=450, y=28)
open2Button.place(x=450, y=78)
open3Button.place(x=450, y=133)
open4Button.place(x=450, y=185)
startButton.place(x=220, y=240)
root.mainloop()







# run = subprocess.Popen( "resources/filler_vm -f resources/maps/map00\
#                             -p1 ./nlavrine.filler -p2 resources/players/carli.filler |\
#                             ./visual.py",
#                             stdin=subprocess.PIPE, shell=True )
    				# command=lambda: update_map(game_map, tableFrame, gameOptions),
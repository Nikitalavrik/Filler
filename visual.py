from tkinter import *

root = Tk()
root.title("Filler")
root.geometry("900x1000")
root.configure(bg = "#080A52")

tableFrame = Frame(root, height=720, width=840, bg="white", highlightthickness=2,
				 highlightbackground="#EB2188", highlightcolor="#EB2188", bd=0)
gameOptions = Frame(root, height=200, width=840, bg="#080A52")
startButton = Button(gameOptions, text="Start", font="Arial 20",
					width=10, height=1, highlightthickness=2,
				 	highlightbackground="#080A52", highlightcolor="#EB2188")
start_text = Label(gameOptions, text="Let`s play ->", font="Arial 50", fg="#EB2188",
					bg="#080A52")

tableFrame.place(x=30, y=30)
gameOptions.place(x=30, y=780)
start_text.place(x=70, y=70)
startButton.place(x=360, y=85)
root.mainloop()

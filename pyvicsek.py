import subprocess

class Wrapper:
    def __init__(self, noise=0.1):
        # code to initalise the object
        self.noise = noise
    
    def run(self):
        command = ["sudo","/mnt/c/Users/ethan/Documents/_Coding Projects/2nd Year/Programming and DA for Scientists/OOP/viscek-cpp", str(self.noise)]
        result = subprocess.run(command, capture_output=True, text=True)
        return result


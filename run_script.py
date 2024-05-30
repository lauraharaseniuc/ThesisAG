import subprocess

def main():
    population = 200
    epochs = 12
    result = subprocess.run(['python', 'main.py', str(0), str(200), str(20)])
    result = subprocess.run(['python', 'main.py', str(0), str(210), str(21)])
    result = subprocess.run(['python', 'main.py', str(0), str(215), str(22)])
    result = subprocess.run(['python', 'main.py', str(0), str(220), str(23)])


main()
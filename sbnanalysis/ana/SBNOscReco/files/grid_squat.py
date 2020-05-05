import time 
import sys
import subprocess

def run(filelists):
    for flist in filelists:
        outfile = flist.split("/")[-1] + ".busy.out"
        with open(flist) as f:
            for line in f:
                busyfile(line.rstrip("\n"), outfile)

# make the file seem busy
def busyfile(fname,outfile="TMP"):
    print fname
    with open(outfile, "w") as f:
        process = subprocess.call(['lar', '-c', 'eventdump.fcl', '-s', fname, '-n', '1'], stdout=f)

def hello(lst):
    print "Running! On files:"
    for name in lst: print name

while True:
    hello(sys.argv[1:])
    run(sys.argv[1:])
    # run every 3 days
    time.sleep(3*24*60*60) 
    print "DONE!"
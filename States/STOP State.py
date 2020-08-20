print("Breaking to a complete STOP....")
command = ""
while(command!="End"):
    print("Subroutine: Disengaged brakes")
    command  = input("Command: ")
    if(command=="Crawl"):
        print("Crawl state")
        exit()

print("END")
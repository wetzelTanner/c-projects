# create image based on ubuntu
FROM ubuntu:20.04

# Update software manager and compiler 
RUN apt -y update && apt install -y build-essential

# Change working directory
WORKDIR /home/root/cs222_proj2

# Copy everything from current directory to the directory in the image
COPY . .

# Compile the source code using the makefile
RUN make

# Serve the compiled app
CMD ["./intproj"]
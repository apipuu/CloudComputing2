# Use the official ubuntu image as a base
FROM ubuntu:latest

# Set noninteractive mode for apt-get
ARG DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    git

# Copy the entire current directory into the image
COPY . /app

# Set the working directory
WORKDIR /app

# Create a build directory
RUN mkdir build

# Run cmake to configure the build
RUN cmake -Bbuild -S . -DCMAKE_BUILD_TYPE=Release

# Build the project
RUN cmake --build build

# Set the default command to run the built executable
CMD ["./build/cppdocker_run"]


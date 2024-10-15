# Use an official GCC runtime as a parent image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Install any needed packages specified in requirements.txt
RUN apt-get update && \
    apt-get install -y cmake

# Build the application
RUN g++ -g src/logger.cpp tests/test_logger.cpp -o tests/test_logger.exe -Iinclude

# Run the application
CMD ["./tests/test_logger.exe"]

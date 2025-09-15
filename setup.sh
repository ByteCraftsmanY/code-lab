#!/bin/bash

# =============================================================================
# C++ & Java Code Lab Setup Script
# =============================================================================
# This script sets up the necessary directory structure and files for the
# C++ & Java Code Lab project, including input/output files for testing.
# =============================================================================

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Function to check if command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Main setup function
main() {
    print_status "Setting up C++ & Java Code Lab environment..."
    
    # Create bin directory
    print_status "Creating bin directory..."
    if mkdir -p ./bin; then
        print_success "Created ./bin directory"
    else
        print_error "Failed to create ./bin directory"
        exit 1
    fi
    
    # Create input file
    print_status "Creating input file..."
    if touch ./bin/'#input.txt'; then
        print_success "Created ./bin/#input.txt"
    else
        print_error "Failed to create input file"
        exit 1
    fi
    
    # Create output file
    print_status "Creating output file..."
    if touch ./bin/'#output.txt'; then
        print_success "Created ./bin/#output.txt"
    else
        print_error "Failed to create output file"
        exit 1
    fi
    
    # Check for C++ compiler
    print_status "Checking for C++ compiler..."
    if command_exists /opt/homebrew/bin/g++-15; then
        print_success "Found g++ compiler: $(/opt/homebrew/bin/g++-15 --version | head -n1)"
    elif command_exists g++; then
        print_success "Found g++ compiler: $(g++ --version | head -n1)"
    elif command_exists clang++; then
        print_success "Found clang++ compiler: $(clang++ --version | head -n1)"
    else
        print_warning "No C++ compiler found. Please install g++"
        print_warning "On macOS: brew install gcc"
        print_warning "On Ubuntu: sudo apt-get install g++"
        print_warning "and change the compiler version here and in the .vscode/settings.json file"
    fi
    
    # Check for Java compiler
    print_status "Checking for Java compiler..."
    if command_exists javac; then
        print_success "Found Java compiler: $(javac -version 2>&1)"
        if command_exists java; then
            print_success "Found Java runtime: $(java -version 2>&1 | head -n1)"
        else
            print_warning "Java runtime not found, but compiler is available"
        fi
    else
        print_warning "No Java compiler found. Please install JDK"
        print_warning "On macOS: brew install openjdk"
        print_warning "On Ubuntu: sudo apt-get install openjdk-24-jdk"
        print_warning "Or download from: https://www.oracle.com/in/java/technologies/downloads/"
    fi
    
    # Set up file permissions
    print_status "Setting up file permissions..."
    chmod 644 ./bin/'#input.txt'
    chmod 644 ./bin/'#output.txt'
    print_success "File permissions set"
    
    print_success "Setup completed successfully! 🎉"
    echo ""
    print_status "Next steps:"
    echo ""
    print_status "For C++:"
    echo "  1. Write your C++ code in any .cpp file"
    echo "  2. Compile with: g++ -std=c++23 -o output filename.cpp"
    echo "  3. Run with: ./output"
    echo ""
    print_status "For Java:"
    echo "  1. Write your Java code in ./java/src/"
    echo "  2. Compile with: javac -d ./java/bin ./java/src/*.java"
    echo "  3. Run with: java -cp ./java/bin Main"
    echo ""
    print_status "Input/Output files are ready in ./bin/"
    print_status "Happy coding! 🚀"
}

# Run main function
main "$@"

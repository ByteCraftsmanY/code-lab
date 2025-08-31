#!/bin/bash

# Project Setup Script
# This script creates the necessary folders and files for the code-lab project

echo "🚀 Setting up code-lab project..."

# Create bin folder inside java folder
echo "📁 Creating bin folder in java directory..."
mkdir -p java/bin

# Create bin folder inside cpp folder  
echo "📁 Creating bin folder in cpp directory..."
mkdir -p cpp/bin

# Create #input.txt files
echo "📄 Creating input files..."
touch java/bin/#input.txt
touch cpp/bin/#input.txt

# Create #output.txt files (if they don't exist)
echo "📄 Creating output files..."
touch java/bin/#output.txt
touch cpp/bin/#output.txt

# Set proper permissions for the script
chmod +x setup.sh

echo "✅ Project setup completed successfully!"
echo ""
echo "📂 Project structure created:"
echo "   ├── java/"
echo "   │   ├── bin/"
echo "   │   ├── #input.txt"
echo "   │   └── #output.txt"
echo "   └── cpp/"
echo "       ├── bin/"
echo "       ├── #input.txt"
echo "       └── #output.txt"
echo ""
echo "🎯 You can now:"
echo "   - Compile Java files: javac -d java/bin java/*.java"
echo "   - Run Java programs: java -cp java/bin ClassName"
echo "   - Compile C++ files: g++ -o cpp/bin/program cpp/program.cpp"
echo "   - Use input/output files for testing"

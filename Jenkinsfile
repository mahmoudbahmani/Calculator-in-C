/*
pipeline {
    agent any

    stages {
        stage('‌Build') {
            steps {
                echo 'started'
                sh 'gcc --version'
            }
        }
        stage('Test'){
            steps{
            sh 'gcc -o executeit main.c'
            }
        }
    }
}
*/
pipeline {
    agent any

    stages {
        stage('without Docker') {
            steps {
                sh 'gcc --version'
            }
        }
        
        stage('with Docker'){
            agent{
                docker{
                    //image 'node:18-alpine'
                    image 'gcc:latest'
                    
                    } 
                }
            
            steps{
                sh 'echo "second one"'
            }
        }
    }
}
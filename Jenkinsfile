
pipeline {
    agent any

    stages {
        stage('‌Build') {
            steps {
                echo 'started'
                sh 'gcc --version'
                sh 'gcc -o executeit main.c'
            }
        }
        stage('Test'){
            steps{
            sh '''test -f executeit
                  echo 'small change'
            '''
            }
        }
        stage('deploy'){
            steps{
                timeout(0) {// wait just for 1 minutes}
                input 'Do you approve?'
            }
        }
    }
    post {
        always{
            junit 'Test-unit/junit.xml'
        }
    }
}
/*
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

pipeline {
    agent any

    environment {
        DOCKER_HOST = "unix:///var/run/docker.sock"  // مسیر Unix Socket
    }

    stages {
        stage('Check Docker') {
            steps {
                sh 'docker --version'
            }
        }
        stage('Run Docker Container') {
            agent {
                docker {
                    image 'gcc:latest'
                }
            }
            steps {
                sh 'echo "Running Docker in Jenkins"'
            }
        }
    }
}
*/
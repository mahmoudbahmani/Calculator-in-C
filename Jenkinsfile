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

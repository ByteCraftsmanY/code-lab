package main

import (
	"fmt"
	"sync"
	"time"
)

type Task interface {
	Execute() string
}

type TestTask struct {
	N int
}

func (r *TestTask) Execute() string {
	return fmt.Sprintf("Executed Task %d", r.N)
}

func Worker(dataChan <-chan Task, workerId int, wg *sync.WaitGroup) {
	defer wg.Done()
	for task := range dataChan {
		fmt.Printf("Worker: %d | %s\n", workerId, task.Execute())
		time.Sleep(time.Second)
	}
}

func StartWorker(dataChan <-chan Task, n int, wg *sync.WaitGroup) {
	for i := 0; i < n; i++ {
		wg.Add(1)
		go Worker(dataChan, i+1, wg)
	}
}

func StartProducer(dataChan chan<- Task) {
	for i := 0; i < 100; i++ {
		dataChan <- &TestTask{N: i + 1}
	}
}

func main() {
	tasks := make(chan Task, 10000)
	fmt.Println("Hello World")
	wg := sync.WaitGroup{}
	StartWorker(tasks, 10, &wg)
	StartProducer(tasks)
	close(tasks)
	wg.Wait()
}

var Queue = function() {
    this.first = null;
    this.size = 0;
  };
  
  var Node = function(data) {
    this.data = data;
    this.next = null;
  };
  
  Queue.prototype.enqueue = function(data) {
    var node = new Node(data);
  
    if (!this.first){
      this.first = node;
    } else {
      n = this.first;
      while (n.next) {
        n = n.next;
      }
      n.next = node;
    }
  
    this.size += 1;
    return node;
  };
  
  Queue.prototype.dequeue = function() {
    temp = this.first;
    this.first = this.first.next;
    this.size -= 1;
    return temp;
  };

  
  var queue = [];
  queue.push(2);         // queue is now [2]
  queue.push(5);         // queue is now [2, 5]
  var i = queue.shift(); // queue is now [5]
  console.log(i);         
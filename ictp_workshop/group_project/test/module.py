class A:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def foo(self,vec):
        self.vec = vec
        for i in range(len(vec)):
            vec[i] +=  self.x
            print vec[i]
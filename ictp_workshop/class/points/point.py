
class Point(object):
   ''' a 2-D geometric point'''
   def __init__(self,x=0,y=0):
      self.x = x
      self.y = y
   def __str__(self):
      return '(%s, %s)' %(self.x,self.y)
   def __add__(self,p2):
      return Point(self.x + p2.x,
                   self.y + p2.y)
   def __sub__(self,p2):
      return Point(self.x - p2.x,
                   self.y - p2.y)
   def dot(self,p2):
      return self.x*p2.x + self.y+p2.y



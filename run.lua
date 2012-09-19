require 'cwdc'

print('Testing C functions')
print('2 + 3 = ',cwdc.add(2,3))
print('2 * 3 = ',cwdc.mul(2,3))
print('')
print('Testing C nn module:')
torch.setdefaulttensortype('torch.FloatTensor')
t = torch.Tensor{-1,1}
abs = nn.ExampleModule()
print('The absolute value of ')
print(t)
print('is')
print(abs:forward(t))
print('And with doubles...')
print('')
torch.setdefaulttensortype('torch.DoubleTensor')
t = torch.Tensor{-1,1}
abs = nn.ExampleModule()
print('The absolute value of ')
print(t)
print('is')
print(abs:forward(t))



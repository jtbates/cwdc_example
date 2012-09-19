-- An example module, same as nn.Abs
local ExampleModule, parent = torch.class('nn.ExampleModule', 'nn.Module')

function ExampleModule:__init()
   parent.__init(self)
end

function ExampleModule:updateOutput(input)
   input.nn.ExampleModule_updateOutput(self, input)
   return self.output
end

function ExampleModule:updateGradInput(input, gradOutput)
   input.nn.ExampleModule_updateGradInput(self, input, gradOutput)
   return self.gradInput
end

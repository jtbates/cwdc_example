----------------------------------------------------------------------
-- description:
--   example of how to build a C for Torch in the current directory,
--   i.e., without installing to search path 
----------------------------------------------------------------------

require 'torch'
require 'nn'

-- create global cwdc table:
cwdc = {}

-- c lib:
require 'libcwdc'

-- example of nn module with generic type
torch.include('cwdc', 'ExampleModule.lua')

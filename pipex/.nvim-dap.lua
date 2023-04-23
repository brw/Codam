require('dap').configurations.c = {
  {
    name = 'Launch pipex',
    type = 'cppdbg',
    request = 'launch',
    program = './pipex',
    args = { 'infile', 'cat', 'cat', 'outfile' },
    cwd = '${workspaceFolder}',
    stopAtEntry = true,
    MIMode = 'gdb',
  }
}

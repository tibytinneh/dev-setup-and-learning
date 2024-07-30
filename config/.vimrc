" WORK-IN-PROGRESS ------------------------uwu-------------- 
" My Vim config file for windows desktop PC at home
" `zo` to open a single fold under the cursor
" `zc` to close the fold under the cursor
" `zR` to open all folds
" `zM` to close all folds
" GENERAL / TABS & INDENTATION ------------------------------------------------------------- {{{

filetype plugin indent on			" Enable file type detection and plugins
syntax on							" Enable syntax highlighting
set nocompatible					" Disable Vi compatibility mode
set encoding=utf-8					" Set default encoding to UTF-8
set fileformat=unix					" Use unix-style line endings 
colorscheme molokai					" Set the color scheme
									" curl -o molokai.vim https://raw.githubusercontent.com/tomasr/molokai/master/colors/molokai.vim
set autoindent						" Auto-indent new lines
" set expandtab						" Convert tabs to space
" set shiftwidth=4					" Number of spaces for each indentation level
" set softtabstop=4					" Number of spaces for Tab key
set tabstop=4						" Number of spaces that a <Tab> in the file counts for
set backspace=indent,eol,start		" Make backspace key work

" }}}
" USER INTERFACE / AUTOCOMPLETE / SEARCH ------------------------------------------------- {{{
set number							" Show line numbers
set ruler							" Show cursor position
" set cursorline					" Highlight cursor line underneath the cursor horizontally 
" set cursorcolumn					" Highlight cursor line underneath the cursor vertically
set showmode						" Display current mode like `-- INSERT --` `-- VISUAL --`
set showcmd							" Show incomplete commands

set wildmenu						" Enable auto completion menu after pressing TAB
set wildmode=list:longest 			" Make wildmenu behave like similar to Bash completion
set wildignore=*.doc,*.jpg,*.png,*.gif,*.pdf,*.pyc,*.exe,*.flv,*.img,*.xlsx
									" Wildmenu will ignore files with these
									" extensions
set hlsearch						" Use highlighting when doing a search
set ignorecase						" Ignore case in search patterns
set smartcase						" Override 'ignorecase' if the search pattern contains uppercase letters
set history=500						" Keep 100 lines of command history
" }}}
" PLUGINS ---------------------------------------------------------------- {{{
" VIM-PLUG -------------{{{
let data_dir = has('nvim') ? stdpath('data') . '/site' : '~/.vim'
" Install vim-plug if not found
if empty(glob(data_dir . '/autoload/plug.vim'))
  silent execute '!curl -fLo '.data_dir.'/autoload/plug.vim --create-dirs  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif
" Run PlugInstall if there are missing plugins
autocmd VimEnter * if len(filter(values(g:plugs), '!isdirectory(v:val.dir)'))
  \| PlugInstall --sync | source $MYVIMRC
\| endif
"}}}
call plug#begin()
Plug 'sheerun/vim-polyglot' " Language pack
Plug 'tomasr/molokai'       " Nice color scheme

"File system explorer  
"    \ NERDTree git status flags  
"    \ NERDTree file icons
Plug 'preservim/nerdtree' |
      \ Plug 'Xuyuanp/nerdtree-git-plugin' |
      \ Plug 'ryanoasis/vim-devicons'

Plug 'tpope/vim-commentary' " Commentary plugin for easy commenting
                            " in normal mode: `gcc`, in visual mode: `gc`
Plug 'junegunn/goyo.vim'
Plug 'junegunn/limelight.vim'
call plug#end()
" NERDTree config---------{{{

" <leader>n to `:NERDTreeFocus` 
"         to focus NERDTree window if it's open
nnoremap <leader>n :NERDTreeFocus<CR>

" `Ctrl+n` to `:NERDTree`
"         to open NERDTree if not open,
"         to focus NERDTree if open.
nnoremap <C-n> :NERDTree<CR>

" 'Ctrl-t' to `:NERDTreeToggle`
"         to toggle visibility
nnoremap <C-t> :NERDTreeToggle<CR>

" `Ctrl+f` to `NERDTreeFind 
"         to locate the current open file in Vim within NERDTree
nnoremap <C-f> :NERDTreeFind<CR>
" }}}

" GOYO / Limelight config------{{{
"Toggle Goyo with Limelight: `:Goyo` `:Goyo!`
autocmd! User GoyoEnter Limelight
autocmd! User GoyoLeave Limelight!
" }}}
"}}}
" VIMSCRIPT -------------------------------------------------------------- {{{
" This will enable code folding.
" Use the marker method of folding.
"
set foldenable
set foldmethod=marker
set foldmarker={{{,}}}

augroup global_folding
    autocmd!
    autocmd BufRead,BufNewFile * setlocal foldmethod=marker | setlocal foldmarker={{{,}}}
augroup END

"
"augroup filetype_vim
"    autocmd!
"     autocmd FileType vim setlocal foldmethod=marker
" augroup END
" }}}

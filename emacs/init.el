(global-set-key (kbd "C-h") 'delete-backward-char)
(global-set-key (kbd "C-w") 'backward-kill-word)
(add-to-list 'load-path "c:/Users/k.kozlov/emacs/")
(load "google-c-style")
(add-hook 'c-mode-common-hook 'google-set-c-style)

(eval-after-load 'autoinsert
  '(define-auto-insert
     '("\\.\\(CC?\\|cc\\|cxx\\|cpp\\|c++\\)\\'" . "Google C++ Style")
     '("Google C++ Style"
       "// Copyright 2019 Samolet LLC" \n
       "// Author: kkozlov" \n
       "// "
       (file-name-nondirectory (buffer-file-name))
       \n \n \n)))

(add-hook 'find-file-hook 'auto-insert)
(set-frame-font "Consolas 10" nil t)
(when window-system
  (tool-bar-mode -1)
  (menu-bar-mode -1)
  (toggle-scroll-bar -1))


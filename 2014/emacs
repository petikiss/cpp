;; ---------------------------------------------------------------------
;; Don't fuck with this part.

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(blink-cursor-mode nil)
 '(case-fold-search t)
 '(column-number-mode t)
 '(current-language-environment "UTF-8")
 '(default-input-method "rfc1345")
 '(global-font-lock-mode t nil (font-lock))
 '(nxml-child-indent 4)
 '(show-paren-mode t nil (paren))
 '(text-mode-hook (quote (turn-on-auto-fill text-mode-hook-identify)))
 '(tool-bar-mode nil))

(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "Terminus" :foundry "xos4" :slant normal :weight normal :height 105 :width normal)))))

;; ---------------------------------------------------------------------
;; TABs and spaces

                                        ; set all kind of TABs to 8 chars
(setq c-basic-offset 4)
(setq default-tab-width 4)
(setq tab-width 4)
(setq py-indent-offset 4)
(setq-default indent-tabs-mode nil)
(setq c-default-style "linux")
(c-set-offset (quote arglist-cont-nonempty) (quote +) nil)
(c-set-offset (quote arglist-intro) (quote +) nil)
(c-set-offset (quote arglist-close) (quote 0) nil)
(c-set-offset (quote case-label) (quote +) nil)
(c-set-offset (quote innamespace) (quote 0) nil)
(c-set-offset (quote access-label) (quote /) nil)

(defun untabify-buffer ()
  "untabify the whole buffer"
  (untabify (point-min) (point-max)))

(add-hook 'c-mode-hook
          (lambda ()
            (add-hook 'before-save-hook 'delete-trailing-whitespace)
            (add-hook 'before-save-hook 'untabify-buffer)))

                                        ; show trailing whitespace at end of lines
(setq-default show-trailing-whitespace t)

                                        ; show empty lines after end of buffer
                                        ;(setq default-indicate-empty-lines t)

;; ---------------------------------------------------------------------
;; reverse video

(set-cursor-color     "white")
(set-foreground-color "white")
(set-background-color "black")

;; ---------------------------------------------------------------------
;; iswitch mode

(iswitchb-mode 1)

(defun iswitchb-local-keys ()
  (mapc (lambda (K)
          (let* ((key (car K)) (fun (cdr K)))
            (define-key iswitchb-mode-map (edmacro-parse-keys key) fun)))
        '(("<right>" . iswitchb-next-match)
          ("<left>"  . iswitchb-prev-match)
          ("<up>"    . ignore)
          ("<down>"  . ignore))))

(add-hook 'iswitchb-define-mode-map-hook 'iswitchb-local-keys)

;; ---------------------------------------------------------------------
;; dired mode

                                        ; 'a' does not open new buffer
(put 'dired-find-alternate-file 'disabled nil)

;; ---------------------------------------------------------------------
;; keybindings

(global-set-key (kbd "<f5>") 'open-dot-emacs)
(global-set-key (kbd "<f6>") 'list-bookmarks)
(global-set-key (kbd "<f7>") 'goto-line)
(global-set-key (kbd "<f8>") 'shell)
(global-set-key (kbd "<f9>") 'compile)

                                        ;(global-set-key (kbd "C-<next>") 'next-buffer)
                                        ;(global-set-key (kbd "C-<prior>") 'previous-buffer)

(global-set-key (kbd "C-c i") 'indent-region)
(global-set-key (kbd "C-c o") 'comment-region)
(global-set-key (kbd "C-c u") 'uncomment-region)
(global-set-key (kbd "C-c m") 'man-follow)
(global-set-key (kbd "C-c f") 'open-file-under-cursor)

(put 'upcase-region 'disabled nil)      ; C-c C-u
(put 'downcase-region 'disabled nil)    ; C-c C-l

(global-set-key (kbd "C-z") 'yank)   ; for querty/quertz compatibility

                                        ; accented characters (for en-us keyboard)
(global-set-key (kbd "C-'  a") "á")
(global-set-key (kbd "C-'  e") "é")
(global-set-key (kbd "C-'  i") "í")
(global-set-key (kbd "C-'  o") "ó")
(global-set-key (kbd "C-;  o") "ö")
(global-set-key (kbd "C-\" o") "ő")
(global-set-key (kbd "C-'  u") "ú")
(global-set-key (kbd "C-;  u") "ü")
(global-set-key (kbd "C-\" u") "ű")

(global-set-key (kbd "C-'  A") "Á")
(global-set-key (kbd "C-'  E") "É")
(global-set-key (kbd "C-'  I") "Í")
(global-set-key (kbd "C-'  O") "Ó")
(global-set-key (kbd "C-;  O") "Ö")
(global-set-key (kbd "C-\" O") "Ő")
(global-set-key (kbd "C-'  U") "Ú")
(global-set-key (kbd "C-;  U") "Ü")
(global-set-key (kbd "C-\" U") "Ű")

                                        ; helper functions

(defun open-dot-emacs ()
  (interactive)
  (find-file "~/.emacs"))

(defun kill-buffer-other-window (arg)
  "Kill the buffer in the other window, and make the current buffer full size. If no other window, kills current buffer."
  (interactive "p")
  (let ((buf (save-window-excursion
               (other-window arg)
               (current-buffer))))
    (delete-windows-on buf)
    (kill-buffer buf)))

;; ---------------------------------------------------------------------
;; shell

(autoload 'ansi-color-for-comint-mode-on "ansi-color" nil t)
(add-hook 'shell-mode-hook 'ansi-color-for-comint-mode-on)

(setq comint-input-ring-size 1024)

;; ---------------------------------------------------------------------
;; LaTeX

(add-hook 'LaTeX-mode-hook
          '(lambda ()
             (turn-on-reftex)
             (local-set-key (kbd "C-c TAB") 'TeX-complete-symbol)
             (ispell-change-dictionary "american")))

(add-hook 'latex-mode-hook 'turn-on-reftex)

(setq reftex-plug-into-AUCTeX t)

;; ---------------------------------------------------------------------
;; remote editing via scp

(require 'tramp)
(setq tramp-default-method "scp")

;; ---------------------------------------------------------------------
;; Make the mouse fuck off when you type.

(mouse-avoidance-mode 'banish)

;; ---------------------------------------------------------------------
;; IRC
                                        ;
                                        ;(require 'rcirc)
                                        ;(require 'rcirc-notify+)
                                        ;
                                        ;(setq rcirc-default-nick "peszilag")
                                        ;(setq rcirc-default-user-name "peszilag")
                                        ;(setq rcirc-default-user-full-name "Peter Szilagyi")
                                        ;(setq rcirc-default-server "eslinuxp01.emea.nsn-net.net")

;; ---------------------------------------------------------------------
;; miscellaneous

                                        ; "y or n" instead of "yes or no"
(fset 'yes-or-no-p 'y-or-n-p)

                                        ; don't make pesky backup~ files
(setq make-backup-files nil)

                                        ; don't use version numbers for backup files
(setq version-control 'never)

                                        ; remove splash screen
(setq inhibit-splash-screen t)
(setq inhibit-startup-echo-area-message t)

;; ---------------------------------------------------------------------
;; stuff

(defun close-all-buffers ()
  (interactive)
  (mapc 'kill-buffer (buffer-list)))

; Use "`" to jump to the matching parenthesis.
(defun goto-match-paren (arg)
  "Go to the matching parenthesis if on parenthesis, otherwise insert the
character typed."
  (interactive "p")
  (cond ((looking-at "\\s\(") (forward-list 1) (backward-char 1))
    ((looking-at "\\s\)") (forward-char 1) (backward-list 1))
    (t (self-insert-command (or arg 1))) ))

(global-set-key "`" `goto-match-paren)

(require 'linum)
(global-linum-mode)


;; ---------------------------------------------------------------------
;; temporary settings for working on a project

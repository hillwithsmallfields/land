(load-library "package")
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages"))
;; this one seems to have become inactive:
;; (add-to-list 'package-archives '("marmalade" . "https://marmalade-repo.org/packages/"))
(add-to-list 'package-archives '("org" . "https://orgmode.org/elpa/") t)
(package-initialize t)
(setq gnutls-algorithm-priority "NORMAL:-VERS-TLS1.3")
(package-refresh-contents)
(dolist (p '("dash"
	     "dash-functional"
	     "ht" "org-ql" "org-super-agenda" "ov" "peg" "s" "ts"))
  (message "installing %s" p)
  (package-install p))

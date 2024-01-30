# 2-puppet_custom_http_response_header.pp

# Install Nginx
package { 'nginx':
  ensure => installed,
}

# Configure Nginx with custom header
file { '/etc/nginx/sites-available/default':
  ensure  => file,
  content => "add_header X-Served-By $hostname;\n",
  notify  => Service['nginx'],
}

service { 'nginx':
  ensure => running,
  enable => true,
}


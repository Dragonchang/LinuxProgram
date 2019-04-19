do_mmap_pgoff
     |
     |-------get_unmapped_area-------mm->get_unmapped_area(arch_get_unmapped_area) 查找可用的地址空间
     |
     |-------mmap_region 创建新vma线性区
                 |
                 |-------find_vma_prepare-------do_munmap vma线性区已经存在进行unmap 成功返回找到的vma
                 | 
                 |-------vma_merge 合并vma线性区
                 |
                 |-------vma = kmem_cache_zalloc-------file->f_op->mmap(file, vma)
                 |
                 |-------vma_link mm->map_count++
